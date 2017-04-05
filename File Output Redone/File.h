/** @file File.h
    @author [Ethan Blank]
    @date [12/21/16]
    
    @brief [Contains the class declarations for InputFile and OutputFile.]
 */

#ifndef File_h
#define File_h

#include <iostream>
#include <fstream>

/** ... */
class InputFile {
    friend InputFile& operator >>(InputFile& fin, int a);
    friend InputFile& operator >>(InputFile& fin, std::string s);
public:
    InputFile(const std::string&);
    ~InputFile();
private:
    std::ifstream input_stream;
};

/** ... */
class OutputFile {
    friend OutputFile& operator <<(OutputFile& fout, int a);
    friend OutputFile& operator <<(OutputFile& fout, std::string s);
public:
    OutputFile(const std::string&);
    ~OutputFile();
private:
    std::ofstream output_stream;
};

#endif /* File_h */
