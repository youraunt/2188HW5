//
//  Functions.hpp
//  2188HW5
//
//  Created by BK Allen on 3/6/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//

#ifndef Functions_hpp
#define Functions_hpp


#include <algorithm>
#include <cassert>
#include <iostream>
#include <fstream>


long getMemoryUsage();

std::string getFileName(int argc, char **argv, std::string &userInput, std::ifstream &infile);

/// @brief Exits program successfully with message
inline std::string exitProgram() {
    std::cout << "Exiting program!" << std::endl;
    /// @brief I used EXIT_SUCCESS here to unwind the stack
    exit(EXIT_SUCCESS);
}

inline void unknownInput() {
    std::cerr << "\nError?! Unknown input.\n" << std::endl;
    exitProgram();
}

[[noreturn]] inline void fileNotFound() {
    std::cerr << "File not found!" << std::endl
              << "Exiting Program!" << std::endl;
    /// @brief winds down stack
    exit(EXIT_FAILURE);
}

std::string makeLowerCase(const std::string &in);

std::string getString(std::ifstream &infile);


std::string getSearch(std::string &userInput, const std::string &searchNumber);


bool loopProgram();

#endif /* Functions_hpp */
