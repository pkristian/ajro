#pragma once


#include <iostream>
#include <vector>
#include "../struct/TokenStruct.h"


class Lexer {
public:
    Lexer();
    tTokenList lex(std::ifstream &fileRecipe);
};
