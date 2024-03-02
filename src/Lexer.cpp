#include "Lexer.h"
#include <iostream>
#include <fstream>

Lexer::Lexer() = default;

void Lexer::lex(std::vector<TokenStruct> &tokenList, std::ifstream &fileRecipe) {

    char c;
    std::string textBuffer;
    TokenStruct ts = {};
    while (!fileRecipe.eof()) {
        fileRecipe.get(c);

        if (c == '%' || c == '\n') {
            if (!textBuffer.empty()) {//new line or token start

                ts.token = TokenEnum::text;
                ts.contents = textBuffer;
                tokenList.push_back(ts);

                textBuffer.erase();
                ts = {};


            }
            if (c == '\n') {
                ts.token = TokenEnum::literalNewLine;
                tokenList.push_back(ts);
                ts = {};


            } else {
                fileRecipe.get(c); // look what is after
                switch (c) {
                    case 'c': {
                        ts.token = TokenEnum::camelCase;
                        break;
                    }
                    case 'P': {
                        ts.token = TokenEnum::pascalCase;
                        break;
                    }
                    case 's': {
                        ts.token = TokenEnum::snakeCase;
                        break;
                    }
                    case 'S': {
                        ts.token = TokenEnum::screamingSnakeCase;
                        break;
                    }
                    case 'k': {
                        ts.token = TokenEnum::kebabCase;
                        break;
                    }
                    case 'A': {
                        ts.token = TokenEnum::loopStart;
                        break;
                    }
                    case 'Z': {
                        ts.token = TokenEnum::loopEnd;
                        break;
                    }
                    case '%': {
                        ts.token = TokenEnum::literalPercent;
                        break;
                    }
                    case 't': {
                        ts.token = TokenEnum::literalTab;
                        break;
                    }
                    case 'T': {
                        ts.token = TokenEnum::literalFakeTab;
                        break;
                    }
                    case 'n': {
                        ts.token = TokenEnum::literalNewLine;
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
    tokenList.push_back(ts);
}


