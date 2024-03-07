#ifndef AJRO_ENTRYSTRUCT_H
#define AJRO_ENTRYSTRUCT_H

#include <string>
#include <vector>


struct EntryStruct {
    std::vector<std::string> words;
};

typedef std::vector<EntryStruct> tEntryList;

#endif //AJRO_ENTRYSTRUCT_H
