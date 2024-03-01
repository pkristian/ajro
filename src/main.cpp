#include <iostream>
#include <array>
#include <fstream>

#include "cmath"
#include "Lexer.h"

#include <vector>

std::vector<std::string> tokens;

void tokenAdd(char c) {

}

void lexer(const std::string &filename) {
    //check file
    std::ifstream stream;
    stream.open(filename);
    if (stream.good()) {
        std::cout << "\x1B[32m" << "Recipe readable" << "\033[0m" << std::endl;
    } else {
        std::cout << "Recipe is shit\n";
        std::exit(1);
    }
    //detokenenize

    char c;
    std::string textBuff;
    std::string toWrite;
    while (!stream.eof()) {
        stream.get(c);

        if (c == '%' || c == '\n') {
            if (!textBuff.empty()) {
                toWrite = "TEXT " + textBuff;
                textBuff.erase();
                ::tokens.push_back(toWrite);
            }
            if (c == '\n') {
                toWrite = "NEWL";
                ::tokens.push_back(toWrite);
            } else {
                stream.get(c);
                switch (c) {
                    case 'c': {
                        toWrite = "CAMEL";
                        break;
                    }
                    case 'P': {
                        toWrite = "PASCAL";
                        break;
                    }
                    case 's': {
                        toWrite = "SNAKE";
                        break;
                    }
                    case 'S': {
                        toWrite = "SCREAMING";
                        break;
                    }
                    case 'k': {
                        toWrite = "KEBAB";
                        break;
                    }
                    case 'A': {
                        toWrite = "START";
                        break;
                    }
                    case 'Z': {
                        toWrite = "END";
                        break;
                    }
                    case '%': {
                        toWrite = "PERCENT";
                        break;
                    }
                    case 't': {
                        toWrite = "TAB";
                        break;
                    }
                    case 'T': {
                        toWrite = "FAKETAB";
                        break;
                    }
                    case 'n': {
                        toWrite = "NEWL";
                        break;
                    }
                    default: {
                        std::cout << "Unrecognised token: %" << c;
                        exit(1);
                        break;
                    }


                }
                ::tokens.push_back(toWrite);

            }


        } else {
            textBuff += c;
        }


    }
    std::cout << "tokens:\n";
    for (
        std::string token: ::tokens
        ) {
        std::cout << token << '\n';
    }


}


int main(int argc, char *argv[]) {


    if (argc != 4) {
        std::cerr << "Please specify files: RECIPE INPUT OUTPUT\n";
        return 1;
    }

    auto pLexer = new Lexer();

    //tokenizer
    lexer(argv[1]);


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


    return 0;
}
