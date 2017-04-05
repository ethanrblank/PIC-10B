/** ... */

#include "File.h"

InputFile& operator >>(InputFile& fin, int a) {
    fin.input_stream >> a;
    return fin;
}

InputFile& operator >>(InputFile& fin, std::string s) {
    fin.input_stream >> s;
    return fin;
}

InputFile::InputFile(const std::string& file) {
    input_stream.open(file);
    if (input_stream.fail()) {
        std::cout << "Error opening: " << file << std::endl;
    }
}

InputFile::~InputFile() {
    std::cout << "File closed." << std::endl;
    input_stream.close();
}

OutputFile& operator <<(OutputFile& fout, int a) {
    fout.output_stream << a;
    return fout;
}

OutputFile& operator <<(OutputFile& fout, std::string s) {
    fout.output_stream << s;
    return fout;
}

OutputFile::OutputFile(const std::string& file) {
    output_stream.open(file);
}

OutputFile::~OutputFile() {
    output_stream.close();
    std::cout << "Done." << std::endl;
}
