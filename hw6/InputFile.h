#ifndef InputFile_h
#define InputFile_h

#include <fstream>
#include <iostream>

/**
 @class InputFile
 
 @brief InputFile class mimics an input function, but designated for files for use of reading integers from a designated file.
 **/

class InputFile {
    friend InputFile& operator>>(InputFile &fin, int a);
public:
    InputFile(const std::string& filename);
    ~InputFile();
private:
    std::ifstream input_stream;
};

#endif
