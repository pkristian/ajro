#ifndef AJRO_LEXER_H
#define AJRO_LEXER_H


#include <iostream>
#include <vector>
#include "TokenStruct.h"

class Lexer {
public:
    Lexer();
    void lex(std::vector<TokenStruct> &tokenList, std::ifstream &fileRecipe);
};


#endif
