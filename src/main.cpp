#include <iostream>
#include <array>
#include <fstream>

#include "cmath"
#include "Lexer.h"
#include "TokenEnum.h"
#include "TokenStruct.h"

#include <vector>

int main(int argc, char *argv[]) {


    if (argc != 4) {
        std::cerr << "Please specify files: RECIPE INPUT OUTPUT\n";
        return 1;
    }

        //check file
    std::ifstream fileRecipe;
    fileRecipe.open(argv[1]);
    if (fileRecipe.good()) {
        std::cout << "\x1B[32m" << "Recipe readable" << "\033[0m" << std::endl;
    } else {
        std::cout << "Recipe is shit\n";
        std::exit(1);
    }

    std::ifstream fileInput;
    fileInput.open(argv[2]);
    if (fileInput.good()) {
        std::cout << "\x1B[32m" << "Input readable" << "\033[0m" << std::endl;
    } else {
        std::cout << "Input is shit\n";
        return 1;
    }
    std::ofstream fileOutput;
    fileOutput.open(argv[3]);
    if (fileOutput.good()) {
        std::cout << "\x1B[32m" << "Output ok" << "\033[0m" << std::endl;
    } else {
        std::cout << "Output is shit\n";
        return 1;
    }

    std::cout << std::endl;

    std::vector<TokenStruct> tokenList;

    auto pLexer = new Lexer();
    pLexer->lex(tokenList, fileRecipe);


    std::cout << "tokens:\n";
    for (
        const TokenStruct& token: tokenList
        ) {
        std::cout << token.token << token.contents << '\n';
    }


    return 0;
}
