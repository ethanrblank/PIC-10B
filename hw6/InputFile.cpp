#include "InputFile.h"

/**
 @param fin
 @param a
 
 @return fin
 
 Utilizes the friend function to overload the >> operator, utilizing an InputFile object, fin, to read ints from a designated file.
 
 **/

InputFile& operator>>(InputFile &fin, int a) {
    fin.input_stream >> a;
    return fin;
}

/**
 @param filename
 
 Constructor for an object of the InputFile class that takes in a string and utilizes that string as the value for the input_stream private variable. If the file cannot be read, the object will go into a fail state and print "Error opening [filename]" to the console.
 **/


InputFile::InputFile(const std::string& filename) : input_stream(filename) {
    if (input_stream.fail())
        std::cout << "Error opening: " << filename << std::endl;
}

/**
 Destructor for an InputFile object. When the object goes out of scope, the file is closed to preserve memory. The function also prints "File closed." to the console so that the user knows that the destructor was successfully called.
 **/


InputFile::~InputFile() {
    input_stream.close();
    std::cout << "File closed." << std::endl;
}
