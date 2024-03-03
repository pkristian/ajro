#ifndef AJRO_COMPILER_H
#define AJRO_COMPILER_H


#include <vector>
#include "TokenStruct.h"

class Compiler {
public:
    Compiler();

    void compile(const tTokenList &tokenList, std::ifstream &fileInput, std::ofstream &fileOutput);

private:
    void interpretToken(TokenStruct &token);

    void interpretToken(TokenStruct &token, std::ifstream &fileInput, std::ofstream &fileOutput);

    void interpretToken(const TokenStruct &token, std::ifstream &fileInput, std::ofstream &fileOutput);
};


#endif
