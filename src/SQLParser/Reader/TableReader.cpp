#include "TableReader.h"

using namespace std;

TableReader::TableReader():SQLParser(){}

TableReader::TableReader(std::string const& filename):SQLParser(filename){}

TableReader::~TableReader(){}



