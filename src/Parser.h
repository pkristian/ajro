#pragma once


#include "struct/TokenStruct.h"


class Parser {
public:
    Parser();

    tTokenList parse(tTokenList &tokenList);
};


