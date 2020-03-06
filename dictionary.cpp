//
//  Dictionary.cpp
//  2188HW5
//
//  Created by BK Allen on 3/6/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//


#include "dictionary.h"

Dictionary::Dictionary() = default;

std::list<DictEntry>
Dictionary::wordFile(const std::string &fileName, std::ifstream &infile, std::list<DictEntry> &list) {
    wordType word;
    assert(infile.is_open());
    do {
        infile >> word;
        auto *newEntry = new DictEntry;
        newEntry->setWord(word);
        list.push_back(*newEntry);
    } while (infile.peek() != EOF);
    return list;
}

int Dictionary::searchForward(std::list<DictEntry> &wordList, wordType &findString) {
    auto wordFound = false;
    auto searchCount = 0;
    for (auto &i : wordList) {
        searchCount += 1;
        if (i.getWord() == findString) {
            wordFound = true;
            break;
        }
    }
    return wordFound ? searchCount : false;
}

int Dictionary::searchBackward(std::list<DictEntry> &wordList, wordType &findString) {
    auto wordFound = false;
    auto searchCount = 0;
    for (auto &i : wordList) {
        searchCount += 1;
        if (i.getWord() == findString) {
            wordFound = true;
            break;
        }
    }
    return wordFound ? searchCount : false;
}

void Dictionary::revPrintList(std::ostream &output, std::list<DictEntry> &wordList) {
    for (auto &i : wordList) {
        output << i.getWord() << " ";
    }
}

void Dictionary::displayList(std::list<DictEntry> &wordList) {
    for (auto &i :wordList) {
        std::cout << i.getWord() << " ";
    }
}
