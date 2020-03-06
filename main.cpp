//
//  main.cpp
//  2188HW5
//
//  Created by BK Allen on 3/6/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//

#include "DictEntry.h"
#include "dictionary.h"
#include "functions.h"

int main(int argc, char **argv) {
    auto again = true;
    unsigned int forwardCounter{};
    unsigned int reverseCounter{};
    std::list<DictEntry> dictionary;
    std::list<DictEntry> toSearch;
    Dictionary();
    wordType dictEntries;
    std::ofstream outfile("../revSorted.txt", std::ios_base::out);
    std::ifstream infile;
    std::ifstream infile1;

    try {
        std::cin.exceptions(std::istream::failbit);
        do {
            std::string dictionaryUserInput = getFileName(argc, argv, dictionaryUserInput, infile);
            std::string searchUserInput = getFileName(argc, argv, searchUserInput, infile1);
            dictionary = Dictionary::wordFile(dictionaryUserInput, infile, dictionary);
            std::cout << "\nDictionary contents: " << std::endl;
            Dictionary::displayList(dictionary);
            dictionary.sort();
            std::cout << "\nSorted dictionary contents: " << std::endl;
            Dictionary::displayList(dictionary);
            toSearch = Dictionary::wordFile(searchUserInput, infile1, toSearch);
            std::cout << "\nWords to search for:" << std::endl;
            Dictionary::displayList(toSearch);
            auto wordToSearch = toSearch.begin();
            do {
                auto temp = wordToSearch->getWord();
                forwardCounter = Dictionary::searchForward(dictionary, temp);
                if (forwardCounter != 0) {
                    std::cout << "\nSearching for: " << temp << std::endl;
                    std::cout << "searchForward iterations: " << forwardCounter << std::endl;
                    reverseCounter = Dictionary::searchBackward(dictionary, temp);
                    std::cout << "searchBackwards iterations: " << reverseCounter << std::endl;
                } else {
                    std::cout << std::endl;
                    std::cout << temp << " is not in this dictionary!" << std::endl;
                }
                ++wordToSearch;
            } while (toSearch.end() != wordToSearch);
            Dictionary::revPrintList(outfile, dictionary);
            again = loopProgram();
        } while (again);
    } catch (const std::exception &exc) {
        std::cerr << exc.what() << std::endl;
        unknownInput();
    }
}
