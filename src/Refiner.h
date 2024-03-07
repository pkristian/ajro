#ifndef AJRO_REFINER_H
#define AJRO_REFINER_H


#include <fstream>
#include "EntryStruct.h"

class Refiner {
public:
    Refiner();
    tEntryList refine(std::ifstream &fileInput);
private:
    void bufferToEntry(std::string &buffer, tEntryList &entryList);

    void bufferToEntry(std::string &buffer, tEntryList *entryList);
};


#endif
