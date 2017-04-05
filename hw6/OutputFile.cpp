#include "OutputFile.h"

/** 
 @param fout
 @param a
 
 @return fout
 
 Utilizes the friend function to overload the << operator and to create an OuputFile object fout to print ints to a designated file.
 
**/

OutputFile& operator <<(OutputFile& fout, int a) {
    fout.output_stream << a;
    return fout;
}

/**
 @param fout
 @param s
 
 @return fout
 
Utilizes the friend function to overload the << operator and to create an OuputFile object fout to print strings to a designated file.

**/

OutputFile& operator <<(OutputFile& fout, std::string s) {
    fout.output_stream << s;
    return fout;
}

/**
 @param fout
 @param c
 
 @return fout
 
 Utilizes the friend function to overload the << operator and to create an OuputFile object fout to print chars to a designated file.
 
 **/

OutputFile& operator <<(OutputFile& fout, char c) {
    fout.output_stream << c;
    return fout;
}

/**
 @param filename
 
 Constructor for an object of the OutputFile class that takes in a string and utilizes that string as the value for the output_stream private varialbe
 **/

OutputFile::OutputFile(const std::string& filename) : output_stream(filename) {}

/**
 Destructor for an OutputFile object. When the object goes out of scope, the file is closed to preserve memory. The function also prints "Done." to the console so that the user knows that the destructor was successfully called.
 **/

OutputFile::~OutputFile() {
    output_stream.close();
    std::cout << "Done." << std::endl;
}
