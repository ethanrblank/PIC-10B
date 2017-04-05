/** @file hw4.cpp
 @author [Ethan Blank]
 @date [10/21/16]
 
 [This program utilizes a class called WordCrawler that takes a string of text and utilizes the class as a pointer to specific words within the string. The crawler can then be used to iterate across the screen. The program allows the user to input text, then the WordCrawler manipulates the user-inuted text and gives data related to the text.]
 
 */

#include <iostream>
#include <string>
#include <vector>

/***** CLASS DECLARATIONS *****/

class WordCrawler {
public:
    WordCrawler();
    WordCrawler(std::string s):words(s) {
        current_word = &words[0];
    }
    WordCrawler& operator++();
    WordCrawler& operator--();
    WordCrawler& operator+=(const int add_by);
    WordCrawler& operator-=(const int subtract_by);
    std::string operator*();
    std::string operator[](size_t n);
    
private:
    std::string words;
    char* current_word; // points to specific char within the string, handy when implementing addition and subtracting and building words.
    
};

/****** FUNCTION DECLARATIONS *******/

int word_count(std::string s);
int the_count(std::string s);
void every_other_in(std::string s);
void print_in_reverse(std::string s);

int main() {
    
    std::string words;
    std::cout << "Please input some words:\n";
    std::getline(std::cin, words);
    std::cout << "The total number of words is : " << word_count(words) << std::endl;
    std::cout<<"The total number of times 'the' appears is: " << the_count(words) << std::endl;
    std::cout << "Every other word is: ";
    every_other_in(words);
    std::cout << std::endl;
    std::cout << "The words in reverse order are : ";
    print_in_reverse(words);
    std::cout << std::endl;
   
    return 0;
}

/**** DEFINITIONS *****/

/**** CLASS DEFINITIONS ****/

WordCrawler::WordCrawler() {}

// Default Constructor

WordCrawler& WordCrawler::operator+=(const int add_by) {
    int space_count = 0;
    while (space_count < add_by) {
        if (*current_word == ' ') {
            ++space_count;
        }
        ++current_word;
    }
    return *this;
}

// Overloaded += operator. I utilized space count because words are separated by spaces. If you want to increment the word crawler by 1 word, the crawler should search until it finds another space.

WordCrawler& WordCrawler::operator++() {
    *this += 1;
    return *this;
}

// Overloaded ++i operator. Utilized the += operator to increment.

WordCrawler& WordCrawler::operator-=(const int subtract_by) {
    int space_count = 0;
    while(space_count <= subtract_by && current_word != 0) {
        if (*current_word == ' ') {
            ++space_count;
        }
        if (current_word != 0)
            --current_word;
    }
    if (current_word == 0) {
        current_word += 2;
    }
    
    else
        ++current_word;
    
    return *this;
}

// Overloaded -= operator. By the same nature as the += operator, the word crawler will search for a space and to find the next word over.

WordCrawler& WordCrawler::operator--() {
    *this -= 1;
    return *this;
}

// Overloaded --i operator. Utilizes the -= operator

std::string WordCrawler::operator[](size_t n) {
    char* temporary_word = current_word;
    size_t space_count = 0;
    while (space_count < n) {
        if (*temporary_word == ' ') {
            ++space_count;
        }
        ++temporary_word;
    }
    std::string return_value = "";
    while (*temporary_word != ' ') {
        return_value += *temporary_word;
        ++temporary_word;
    }
    return return_value;
}

// returns a new variable so that the WordCrawler position remains constant. Can be used when implementing a WordCrawler and then the user can search the indeces of a string for a specific word.

std::string WordCrawler::operator*() {
    std::string return_value = "";
    while (*current_word != ' ' && *current_word != 0) {
        return_value += *current_word;
        ++current_word;
    }
    return return_value;
}
// The operator* allows the WordCrawler to act as a pointer reference. I again utilized my return_value variable so build strings of individual words.



/**** FUNCTION DEFINITIONS ****/

/** Builds on numberWords for each word included in the string. Returns numberWord. **/

int word_count(std::string s) {
    WordCrawler p(s); // initialize a WordCrawler
    int string_position = 0;
    int numberWords = 0;
    while (string_position < s.length()-1) {
        std::string t = *p; //Create a string that points to p
        if (t != "") {
            numberWords++;
            string_position += (t.length() + 1);
        }
        if (string_position < s.length() - 1)
            ++p;
    }
    return numberWords;
}

/** Counts the number of times the word "the" appears in the string by utilizing the string and referencing it to the 
    WordCrawler p. When a "the" is found, numberThe increments.
 
 returns an integer numberThe

**/

int the_count(std::string s) {
    WordCrawler p(s);
    int numberThe = 0;
    int string_position = 0;
    
    while (string_position < s.length()-1) {
        std::string t = *p;
        if (t != "") {
            string_position += (t.length() + 1);
            if (t == "the" || t == "The" || t == "THE" || t == "tHe" || t == "thE" || t == "THe" || t == "tHE" || t== "ThE")
                numberThe++;
        }
        if (string_position < s.length() - 1)
            ++p;
    }
    
    return numberThe;
}

/** Prints every odd word in the string by utilizing i and checking to make sure if the WordCrawler is on an odd or even word.

 **/

void every_other_in(std::string s) {
    WordCrawler p(s);
    int i = 1;
    int string_position = 0;
    
    while (string_position < s.length()) {
        std::string t = *p;
        if (t != "") {
            string_position += (t.length()+1);
            if (i%2 == 1) {
                std::cout << t << " ";
            }
        }
        if (string_position < s.length() - 1) {
            ++p;
            ++i;
        }
    }
}
/**  Utilizes a vector of strings to more simply print the words in reverse order. **/

void print_in_reverse(std::string s) {
    std::vector<std::string> f;
    std::string temp = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            temp += s[i];
        }
        else {
            f.push_back(temp);
            temp = "";
        }
    }
    f.push_back(temp);
    
    for (int i = (int)(f.size())-1; i >= 0; --i) {
        std::cout << f[i] << " ";
    }
}
