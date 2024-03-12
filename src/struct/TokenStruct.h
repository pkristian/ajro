#pragma once

#include <string>
#include "../enum/TokenEnum.h"


struct TokenStruct {
    TokenEnum token;
    std::string contents;
    std::vector<TokenStruct> children = {};
    bool typeCase = false;
    bool typeLiteral = false;
    bool typeControl = false;
};

typedef std::vector<TokenStruct> tTokenList;

