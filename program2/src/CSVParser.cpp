#include "../include/CSVParser.h"

#include <string>

CSVParser::CSVParser(const std::string &_filepath, unsigned int _maxRows, unsigned int _maxCols)
{
    this->maxRows = _maxRows;
    this->maxCols = _maxCols;
    this->capacity = _maxRows * _maxCols;
    this->size = 0; 
    this->filepath = _filepath;
    
    this->data = new std::string[this->capacity];
}

std::string CSVParser::getData(unsigned int row, unsigned int col) const
{
    return this->data[row * (this->maxCols + 1) + col]; 
}

unsigned int CSVParser::getSize() const
{
    return this->size;
}

bool CSVParser::openFile()
{
    this->file.open(this->filepath);
    return !this->file.is_open();
}

void CSVParser::readFile()
{
    std::string line;
    char delimiter = ',';
    char newLine = '\n';
    char returnLine = '\r';

    unsigned int index = 0;
    std::string token;

    while(std::getline(this->file, line)) {
        token.clear();
        for(unsigned int i = 0; i < line.size(); ++i) {
            if(line.at(i) == delimiter || line.at(i) == newLine || line.at(i) == returnLine) {
                this->data[index] = token;
                
                this->size++;
                index++;
                token.clear();
            } else {
                token += line.at(i);   
            }
        }
    }
    this->closeFile();
}

void CSVParser::closeFile()
{
    this->file.close();
}
