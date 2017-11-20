#include <zlib.h>
#include <iostream>
#include <fstream>
#include <sstream>


int main() {

    std::string fname("test.txt");
    std::ifstream file_in(fname.c_str());

    std::stringstream str_stream;
    str_stream << file_in.rdbuf();//read the file
    std::string content = str_stream.str();

    gzFile gz_file = gzopen("test.gz", "w9");
    gzwrite(gz_file, content.c_str(), content.size() * sizeof(char));

    gzclose(gz_file);
    return 0;
}