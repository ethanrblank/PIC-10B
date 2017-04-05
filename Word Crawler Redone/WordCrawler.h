/** @file WordCrawler.h
    @author [Ethan Blank]
    @date [12/16/16]
 
    @brief [A class that mimics an iterator object for strings. The crawler iterates through individual words, not characters.]
 */

#ifndef WordCrawler_h
#define WordCrawler_h

#include <iostream>

class WordCrawler {
public:
    WordCrawler();
    WordCrawler(std::string);
    WordCrawler& operator++();
    WordCrawler& operator--();
    WordCrawler& operator-=(const int);
    WordCrawler& operator+=(const int);
    std::string operator*() const;
    std::string operator[](unsigned int);
    
private:
    std::string words;
    char* current_word;
};


#endif /* WordCrawler_h */
