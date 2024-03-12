#pragma once


#include <fstream>
#include "struct/EntryStruct.h"

class Refiner {
public:
    Refiner();
    tEntryList refine(std::ifstream &fileInput);
private:
    void bufferToEntry(std::string &buffer, tEntryList &entryList);

    void bufferToEntry(std::string &buffer, tEntryList *entryList);
};


