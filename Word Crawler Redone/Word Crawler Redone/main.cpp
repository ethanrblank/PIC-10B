/** @file main.cpp
    @author [Ethan Blank]
    @date [12/20/16]
 
    @brief [The user inputs some text, then utilizing a custom class called WordCrawler, the program iterates throughout the string by whole words and is able to provide the user with some statistics regarding his or her input.]
 */

#include <iostream>
#include <vector>
#include "WordCrawler.h"

unsigned int word_count(std::string);
unsigned int the_count(std::string);
void every_other_in(std::string);
void print_in_reverse(std::string);


int main () {
    std::string words;
    
    std::cout << "Please input some words:\n";
    std::getline(std::cin, words);
    
    std::cout << "The total number of words is: " << word_count(words) << std::endl;
    
    std::cout << "The total number of times 'the' appears is: " << the_count(words) << std::endl;
    
    std::cout << "Every other word is: "; every_other_in(words); std::cout << std::endl;
    
    std::cout << "The words in reverse order are: "; print_in_reverse(words); std::cout << std::endl;
    
    return 0;
}


/** @param phrase (string)
    @return count (unsigned int)
    [Cycles through the entire string and increments count by one everytime the crawler arrives at a new word.]
 */
unsigned int word_count (std::string phrase) {
    WordCrawler crawler(phrase);
    unsigned int count = 0;
    while (*crawler != "\0") {
        ++count;
        ++crawler;
    }
    return count;
}

/** @param phrase (string)
    @return count (unsigned int)
    [Cycles through the entire string and increments count by one everytime the crawler arrives at a variation of the word 'the'.]
 */
unsigned int the_count(std::string phrase) {
    WordCrawler crawler(phrase);
    unsigned int count = 0;
    while (*crawler != "\0") {
        if (*crawler == "the" || *crawler == "THE" || *crawler == "The" || *crawler == "tHe" || *crawler == "thE" || *crawler == "THe" || *crawler == "tHE" || *crawler == "ThE")
            ++count;
        ++crawler;
    }
    return count;
}

/** @param phrase (string)
    [Cycles through the entire string but only prints every even word.]
 */
void every_other_in(std::string phrase) {
    WordCrawler crawler(phrase);
    int i = 0;
    while (*crawler != "\0") {
        if (!(i%2))
            std::cout << *crawler << " ";
        ++i;
        ++crawler;
    }
}

/** @param phrase (string)
    [Cycles through the string and adds each word to a vector called 'backwards'. Then the function reverse traverses through that vector and prints each word.]
 */
void print_in_reverse(std::string phrase) {
    WordCrawler crawler(phrase);
    std::vector<std::string> backwards(0);
    while (*crawler != "\0") {
        backwards.push_back(*crawler);
        ++crawler;
    }
    for (int i = (int)backwards.size() - 1, p = 0; i >= p; --i) {
        std::cout << backwards[i] << " ";
    }
}
