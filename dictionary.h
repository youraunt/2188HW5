//
//  Dictionary.hpp
//  2188HW5
//
//  Created by BK Allen on 3/6/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <list>
#include <iostream>
#include <fstream>
#include "DictEntry.h"
#include <boost/range/adaptor/reversed.hpp>
class Dictionary {
public:
    Dictionary();

    static std::list<DictEntry>
    wordFile(const std::string &fileName, std::ifstream &infile, std::list<DictEntry> &list);

    /*Searches the list starting at the front of the list and moving to the back
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    static int searchForward(std::list<DictEntry> &wordList, wordType &findString);

    /*Searches the list starting at the back of the list and moving to the front
     Returns the number of searches it took to find the findString, or a -1 if not found*/
    static int searchBackward(std::list<DictEntry> &wordList, wordType &findString);

    /*Prints the list of words in reverse alphabetic order to a file*/
    static void revPrintList(std::ostream &output, std::list<DictEntry> &wordList);


};


#endif /* Dictionary_hpp */
