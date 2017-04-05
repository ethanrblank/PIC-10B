/** @file WordCrawler.cpp
    @author [Ethan Blank]
    @date [12/16/16]
    
    [Contains the member function definitions for the file WordCrawler.h.]
 */

#include "WordCrawler.h"

/** Default constructor for the WordCrawler class */
WordCrawler::WordCrawler() {
    words = "";
    current_word = nullptr;
}

/** Regular constructor. Sets "words" to a given string and "current_word" to point to the first character in the string */
WordCrawler::WordCrawler(std::string s) {
    words = s;
    current_word = &words[0];
}

/** @return *this += 1
    [Utilizes the overloaded += operator to increment the WordCrawler by 1 word, then returns it.]
 */
WordCrawler& WordCrawler::operator++() {
    return *this += 1;
}

/** @return *this -= 1
    [Utilizes the overloaded -= operator to decrement the WordCrawler by 1 word, then returns it.]
 */
WordCrawler& WordCrawler::operator--() {
    return *this -= 1;
}

/** @param spaces (const int)
    @return *this
    [Overloaded -= operator to move the WordCrawler backwards through the string.]
 */
WordCrawler& WordCrawler::operator-=(const int spaces) {
    int space_count = 0;
    
    while (space_count <= spaces) {
        if (*current_word == ' ') { // When it arrives at a space, it increases the space count.
            ++space_count;
        }
        if (current_word != &words[0])
            --current_word; // Moves current_word backwards through the string
        if (current_word == &words[0])
            return *this;
    }
    
    ++current_word; // When moving backwards, the WordCrawler needs to check for an additional space, so that it begins at the start of the word. Therefore the crawler should then move forward two spaces so it starts at the correct position.
    ++current_word;
    
    return *this;
}

/** @param spaces (const int)
    @return *this
    [Overloaded += operator to move the WordCrawler forwards through the string]
 */
WordCrawler& WordCrawler::operator+=(const int spaces) {
    int space_count = 0;
    while (space_count < spaces) {
        if (*current_word == ' ')
            ++space_count;
        if (*current_word == '\0')
            return *this;
        ++current_word;
    }
    return *this;
}

/** @return return_value (string)
    [Mimics the dereference operator for iterators. Returns a string variable for the word that the WordCrawler is pointing at.]
 */
std::string WordCrawler::operator*() const {
    std::string return_value = ""; // creates an empty string
    char* copy = current_word; // creates a copy of current_word so that its position is not disrupted
    while (*copy != ' ' && copy != &words[words.size()]) { // if copy is not a space or the end of the string add the chars to return_value
        return_value += *copy;
        ++copy;
    }
    return return_value;
}

/** @param value (unsigned int)
    @return return_value (string)
    [Mimics the index operator []. Returns the word at the index {value} positions away from the current position of the WordCrawler.]
 */
std::string WordCrawler::operator[](unsigned int value) {
    WordCrawler temp = *this; // makes a copy of current_word so that it does not disrupt its current position
    temp += value;
    return *temp;
}
    
