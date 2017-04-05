#ifndef OutputFile_h
#define OutputFile_h

#include <iostream>
#include <fstream>

/**
 @class OutputFile
 
 @brief OutputFile class mimics a printing function, but designated for files for use of creating and printing text, numbers, and chars to a designated file
 **/

class OutputFile {
    friend OutputFile& operator <<(OutputFile& fout, int a);
    friend OutputFile& operator <<(OutputFile& fout, std::string s);
    friend OutputFile& operator <<(OutputFile& fout, char c);
public:
    OutputFile(const std::string& filename);
    ~OutputFile();
    
private:
    std::ofstream output_stream;
};

#endif /* OutputFile_h */
