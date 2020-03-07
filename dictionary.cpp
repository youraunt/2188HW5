//
//  Dictionary.cpp
//  2188HW5
//
//  Created by BK Allen on 3/6/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//

for (
auto i = wordList.rbegin();
i != wordList.

rend();

++i)

#include "dictionary.h"

Dictionary::Dictionary() = default;

std::list<DictEntry>
Dictionary::wordFile
        (const std::string &fileName, std::ifstream &infile, std::list<DictEntry> &list) {
    assert(infile.is_open());
    wordType word;
    do {
        infile >> word;
        auto *newEntry = new DictEntry;
        newEntry->setWord(word);
        list.push_back(*newEntry);
    } while (infile.peek() != EOF);
    return list;
}

int Dictionary::searchForward(std::list<DictEntry> &wordList, wordType &findString) {
    auto inDict = false;
    auto count = 0;
    for (auto &i : wordList) {
        count += 1;
        if (i.getWord() == findString) {
            inDict = true;
            break;
        }
    }
    return inDict ? count : false;
}

int Dictionary::searchBackward(std::list<DictEntry> &wordList, wordType &findString) {
    auto inDict = false;
    auto count = 0;
    /*for (auto i = wordList.rbegin(); i != wordList.rend(); ++i)*/
    for (auto &i : boost::adaptors::reverse(wordList)) {
        count += 1;
        if (i.getWord() == findString) {
            inDict = true;
            break;
        }
    }
    return inDict ? count : false;
}

void Dictionary::revPrintList(std::ostream &output, std::list<DictEntry> &wordList) {
    for (auto &i : wordList) {
        output << i.getWord() << " ";
    }
}


