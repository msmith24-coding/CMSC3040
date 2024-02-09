#ifndef CSV_PARSER_H_
#define CSV_PARSER_H_

#include <fstream>
#include <string>

class CSVParser
{
    public: // Constructors.
        CSVParser(const std::string &filepath, unsigned int maxRows, unsigned int maxCols);
    private: // Member Variables.
        unsigned int maxRows;
        unsigned int maxCols;
        unsigned int capacity;
        unsigned int size;
        std::ifstream file;
        std::string filepath;
        std::string* data;
    public: // Member Getter Methods.
        std::string getData(unsigned int row, unsigned int col) const;
        unsigned int getSize() const;
    public: // Member Utility Methods.
        bool openFile();
        void readFile();
        void closeFile();
};

#endif // !CSV_PARSER_H_
