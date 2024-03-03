#include <vector>
#include <iostream>
#include "Parser.h"
#include "TokenStruct.h"


Parser::Parser() = default;

tTokenList Parser::parse(tTokenList &tokenList) {

    tTokenList parsedTokenList = {};

    bool caseUsedInside = false;
    bool caseUsedOutside = false;
    bool loopUsed = false;
    bool insideLoop = false;
    bool pushToken = false;


    for (
        const TokenStruct &token: tokenList
        ) {
        if (token.token == TokenEnum::eof) {
            goto endParsing;
        }


        if (token.typeLiteral) {
            pushToken = true;

        } else if (token.typeCase) {
            if (insideLoop) {
                caseUsedInside = true;
            } else {
                caseUsedOutside = true;
            }
            pushToken = true;

        } else if (token.typeControl) {
            if (token.token == TokenEnum::loopStart) {
                loopUsed = true;
                if (insideLoop) {
                    throw "cannot loop inside a loop";
                }
                insideLoop = true;
                parsedTokenList.push_back(token); //need to push back manually
            } else if (token.token == TokenEnum::loopEnd) {
                if (!insideLoop) {
                    throw "cannot jump out of loop if not in any";
                }
                insideLoop = false;
            }
        } else {
            throw "there is token we do not recognise as any category";
        }

        if (caseUsedInside && caseUsedOutside) {
            throw ("Cannot use case inside and outside a loop");
        }


        if (pushToken) {
            if (insideLoop) {
                parsedTokenList.back().children.push_back(token);

            } else {
                parsedTokenList.push_back(token);
            }
            pushToken = false;
        }


    }

    endParsing:
    if (!loopUsed) {
        TokenStruct masterLoop = {};
        masterLoop.typeControl = true;
        masterLoop.token = TokenEnum::loopStart;
        masterLoop.children = parsedTokenList;

        parsedTokenList = {};
        parsedTokenList.push_back(masterLoop);
    }


    return parsedTokenList;

}