#ifndef AJRO_PARSER_H
#define AJRO_PARSER_H


#include "TokenStruct.h"



class Parser {
public:
    Parser();

    tTokenList parse(tTokenList &tokenList);
};


#endif
