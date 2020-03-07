//
//  DictEntry.h
//  2188HW5
//
//  Created by BK Allen on 3/6/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//

#ifndef DictEntry_h
#define DictEntry_h


#include <string>
#include <utility>

typedef std::string wordType;

class DictEntry {
private:
    wordType word;

public:
    wordType getWord() { return word; }

    void setWord(wordType _word) { word = std::move(_word); }

    bool operator<(const DictEntry &entry) const { return (word < entry.word); }
};


#endif /* DictEntry_h */
