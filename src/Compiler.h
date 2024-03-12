#pragma once


#include <vector>
#include "struct/TokenStruct.h"
#include "struct/EntryStruct.h"

class Compiler {
public:
    Compiler(
        tTokenList &tokenList,
        tEntryList &entryList,
        std::ofstream &fileOutput
        );

    void compile();

private:
    void interpretToken(const TokenStruct &token);
    tTokenList *tokenList;
    tEntryList *entryList;
    std::ofstream *fileOutput;

    void printCase(TokenEnum &token, EntryStruct &entry);

    void printCase(TokenEnum token, EntryStruct &entry);
};


