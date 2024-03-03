#include <fstream>
#include "Compiler.h"
#include "TokenStruct.h"

Compiler::Compiler() = default;

void Compiler::compile(
    const tTokenList &tokenList,
    std::ifstream &fileInput,
    std::ofstream &fileOutput
) {
    for (
        const TokenStruct &token: tokenList
        ) {
        interpretToken(token, fileInput, fileOutput);
    }


}

void Compiler::interpretToken(
    const TokenStruct &token,
    std::ifstream &fileInput,
    std::ofstream &fileOutput
) {
    if (token.typeLiteral) {
        switch (token.token) {
            case text: {
                fileOutput << token.contents;
                break;
            }
            case literalPercent: {
                fileOutput << "%";
                break;
            }
            case literalTab: {
                fileOutput << "\t";
                break;
            }
            case literalFakeTab: {
                fileOutput << "    ";
                break;
            }
            case literalNewLine: {
                fileOutput << "\n";
                break;
            }
        }
    } else if (token.typeCase) {
        switch (token.token) {
            case camelCase: {
                fileOutput << "camelCase";
                break;
            }
            case pascalCase: {
                fileOutput << "PascalCase";
                break;
            }
            case snakeCase: {
                fileOutput << "snake_case";
                break;
            }
            case screamingSnakeCase: {
                fileOutput << "SCREAMING_SNAKE_CAS";
                break;
            }
            case kebabCase: {
                fileOutput << "kebab-case";
                break;
            }

        }
    } else if (token.token == loopStart) {
        std::vector<std::string> entryList = {};
        entryList.push_back("first");
        entryList.push_back("second");
        entryList.push_back("thirth");
        entryList.push_back("fotrh");
        for (
            auto &entry: entryList
            ) {
            for (
                const TokenStruct &childToken: token.children
                ) {
                interpretToken(childToken, fileInput, fileOutput);
            }

        }

    }


}
