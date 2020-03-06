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

typedef std::string wordType;

class DictEntry {
private:
    wordType word;
    wordType definition;

public:
    wordType getWord() { return word; }

    void setWord(wordType _word) { word = _word; }

//    wordType getDef() { return definition; }
//    void setDef(wordType _def) { definition = _def; }

    bool operator<(const DictEntry &entry) const {
        return (word < entry.word);
    }

};


#endif /* DictEntry_h */
