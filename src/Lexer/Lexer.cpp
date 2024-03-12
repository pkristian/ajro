#include "Lexer.h"
#include <iostream>
#include <fstream>

Lexer::Lexer() = default;

tTokenList Lexer::lex(std::ifstream &fileRecipe) {

    tTokenList tokenList;
    char c;
    std::string textBuffer;
    TokenStruct ts = {};
    while (!fileRecipe.eof()) {
        fileRecipe.get(c);

        if (c == '%' || c == '\n') {
            if (!textBuffer.empty()) {//new line or token start

                ts.token = TokenEnum::text;
                ts.contents = textBuffer;
                ts.typeLiteral = true;
                tokenList.push_back(ts);

                textBuffer.erase();
                ts = {};


            }
            if (c == '\n') {
                ts.token = TokenEnum::literalNewLine;
                ts.typeLiteral = true;
                tokenList.push_back(ts);
                ts = {};


            } else {
                fileRecipe.get(c); // look what is after
                switch (c) {
                    case 'c': {
                        ts.token = TokenEnum::camelCase;
                        ts.typeCase = true;
                        break;
                    }
                    case 'P': {
                        ts.token = TokenEnum::pascalCase;
                        ts.typeCase = true;
                        break;
                    }
                    case 's': {
                        ts.token = TokenEnum::snakeCase;
                        ts.typeCase = true;
                        break;
                    }
                    case 'S': {
                        ts.token = TokenEnum::screamingSnakeCase;
                        ts.typeCase = true;
                        break;
                    }
                    case 'k': {
                        ts.token = TokenEnum::kebabCase;
                        ts.typeCase = true;
                        break;
                    }
                    case 'A': {
                        ts.token = TokenEnum::loopStart;
                        ts.typeControl = true;
                        break;
                    }
                    case 'Z': {
                        ts.token = TokenEnum::loopEnd;
                        ts.typeControl = true;
                        break;
                    }
                    case '%': {
                        ts.token = TokenEnum::literalPercent;
                        ts.typeLiteral = true;
                        break;
                    }
                    case 't': {
                        ts.token = TokenEnum::literalTab;
                        ts.typeLiteral = true;
                        break;
                    }
                    case 'T': {
                        ts.token = TokenEnum::literalFakeTab;
                        ts.typeLiteral = true;
                        break;
                    }
                    case 'n': {
                        ts.token = TokenEnum::literalNewLine;
                        ts.typeLiteral = true;
                        break;
                    }
                    default: {
                        std::cout << "Unrecognised token: %" << c;
                        exit(1);
                        break;
                    }
                }

                //add token we have just seen
                tokenList.push_back(ts);
                ts = {};

            }


        } else {
            textBuffer += c;
        }


    }

    //add end of file at the end for parser
    ts.token = TokenEnum::eof;
    ts.typeControl = true;
    tokenList.push_back(ts);

    return tokenList;
}