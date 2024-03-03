#ifndef AJRO_TOKENSTRUCT_H
#define AJRO_TOKENSTRUCT_H

#include <string>
#include "TokenEnum.h"


struct TokenStruct {
    TokenEnum token;
    std::string contents;
    std::vector<TokenStruct> children = {};
    bool typeCase = false;
    bool typeLiteral = false;
    bool typeControl = false;
};

typedef std::vector<TokenStruct> tTokenList;

#endif //AJRO_TOKENSTRUCT_H
