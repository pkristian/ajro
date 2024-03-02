#ifndef AJRO_TOKENSTRUCT_H
#define AJRO_TOKENSTRUCT_H

#include <string>
#include "TokenEnum.h"

struct TokenStruct {
    TokenEnum token;
    std::string contents;
};
#endif //AJRO_TOKENSTRUCT_H
