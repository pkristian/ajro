#include <cstring>
#include "Refiner.h"
#include "./struct/EntryStruct.h"


Refiner::Refiner() = default;


tEntryList Refiner::refine(std::ifstream &fileInput) {

    tEntryList entryList;
    char c;
    std::string textBuffer;
    EntryStruct es = {};


    while (!fileInput.eof()) {
        fileInput.get(c);


        if (c == '\n' || c == '\r') {
            //boundary found
            Refiner::bufferToEntry(textBuffer, entryList);
        } else {
            //increase buffer
            textBuffer += c;
        }
    }
    Refiner::bufferToEntry(textBuffer, entryList);

    return entryList;
}

void Refiner::bufferToEntry(std::string &buffer, tEntryList &entryList) {
    EntryStruct entryStruct = {};
    std::string clean;

    bool started = false;
    int lastCharPosition = 0;
    int i = 0;
    for (
        char &c: buffer
        ) {
        i++;
        if (std::strchr(" \n\r\t", c)) {
            if (!started) {
                continue;
            }
            clean += c;
        } else {
            started = true;
            lastCharPosition = i;

            clean += c;
        }
    }
    buffer.clear();

    clean = clean.substr(0, lastCharPosition);

    if (clean.empty()) {
        return;
    }

    //ready to explode into words

    bool lowercasePresent = false;
    bool separatorsUsed = false;

    clean += (char) 0;//null terminator :)
    std::string word;
    for (
        char &c: clean
        ) {

        bool needSplit = false;
        bool isUsable = false;
        bool isExtended = (((int) c) < 0);//some unicode nonsence
        bool isNumber = (c >= 48 && c <= 57);
        bool isUpper = (c >= 65 && c <= 90);
        bool isLower = (c >= 97 && c <= 122);
        bool isOtherInRange = !isExtended && !isNumber && !isUpper && !isLower;

        if (isLower) {
            lowercasePresent = true;
        }

        if (isOtherInRange) {
            needSplit = true;
            separatorsUsed = true;
        } else {
            isUsable = true;
        }
        if (isUpper && lowercasePresent && !separatorsUsed) {
            needSplit = true;
        }


        if (needSplit) {
            entryStruct.words.push_back(word);
            word.clear();
        }


        if (isUsable) {
            word += (char) tolower(c);
        }

    }


    if (!entryStruct.words.empty()) {
        entryList.push_back(entryStruct);
    }


}
