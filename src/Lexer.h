#ifndef AJRO_LEXER_H
#define AJRO_LEXER_H


#include <iostream>
#include <vector>
#include "TokenStruct.h"

class Lexer {
public:
    Lexer();
    tTokenList lex(std::ifstream &fileRecipe);
};


#endif
