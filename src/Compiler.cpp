#include <fstream>
#include "Compiler.h"
#include "TokenStruct.h"
#include "EntryStruct.h"


Compiler::Compiler(
    tTokenList &tokenList,
    tEntryList &entryList,
    std::ofstream &fileOutput
) {
    this->tokenList = &tokenList;
    this->entryList = &entryList;
    this->fileOutput = &fileOutput;


}

void Compiler::compile(
) {
    for (
        const TokenStruct &token: *this->tokenList
        ) {
        interpretToken(token);
    }


}

void Compiler::interpretToken(const TokenStruct &token) {
    if (token.typeLiteral) {
        switch (token.token) {
            case text: {
                *this->fileOutput << token.contents;
                break;
            }
            case literalPercent: {
                *this->fileOutput << "%";
                break;
            }
            case literalTab: {
                *this->fileOutput << "\t";
                break;
            }
            case literalFakeTab: {
                *this->fileOutput << "    ";
                break;
            }
            case literalNewLine: {
                *this->fileOutput << "\n";
                break;
            }
        }
    } else if (token.token == loopStart) {
        for (
            auto &entry: *this->entryList
            ) {
            for (
                const TokenStruct &childToken: token.children
                ) {
                if (childToken.typeCase) {
                    printCase(childToken.token, entry);
                } else {
                    interpretToken(childToken);
                }
            }

        }

    }


}

void Compiler::printCase(TokenEnum token, EntryStruct &entry) {

    std::string separator = {};
    bool firstFirstUpper = false;
    bool firstUpper = false;
    bool allUpper = false;

    int wordNum = 0;

    switch (token) {
        case camelCase: {
            firstUpper = true;
            break;
        }
        case pascalCase: {
            firstFirstUpper = true;
            firstUpper = true;
            break;
        }
        case snakeCase: {
            separator = '_';
            break;
        }
        case screamingSnakeCase: {
            allUpper = true;
            separator = '_';
            break;
        }
        case kebabCase: {
            separator = '-';
            break;
        }
    }


    for (
        std::string word: entry.words
        ) {
        wordNum++;


        if (allUpper) {

            for (
                char &c: word
                ) {
                c = (char) toupper(c);

            }
        } else if (firstUpper) {
            if (wordNum != 1 || firstFirstUpper) {
                word[0] = (char) toupper(word[0]);

            }

        }


        *this->fileOutput << word;

        if (wordNum < entry.words.size()) {
            *this->fileOutput << separator;
        }

    }


}
