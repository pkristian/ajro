#include <iostream>
#include <array>
#include <fstream>
#include <vector>
#include "cmath"

#include "./loader.h"



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


    auto pLexer = new Lexer();
    tTokenList tokenList = pLexer->lex(fileRecipe);

    auto pParser = new Parser();
    tTokenList parsedTokenList = pParser->parse(tokenList);

    auto pRefiner = new Refiner();
    tEntryList entryList = pRefiner->refine(fileInput);

    auto pCompiler = new Compiler(parsedTokenList, entryList, fileOutput);
    pCompiler->compile();


    return 0;
}
