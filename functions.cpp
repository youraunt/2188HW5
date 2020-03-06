//
//  Functions.cpp
//  2188HW5
//
//  Created by BK Allen on 3/6/20.
//  Copyright © 2020 BK Allen. All rights reserved.
//

#include "functions.h"
//
// Created by BK Allen on 2/21/20.
//


#include <sys/resource.h>

long getMemoryUsage() {
    struct rusage usage{};
    if (0 == getrusage(RUSAGE_SELF, &usage))
        return usage.ru_maxrss; // bytes
    else
        return 0;
}

/// @brief Handles user input with option of entering filename at command line
/// @param argc (argument count) the number of strings pointed to by argv should be 1+
/// @param argv (argument vector) A one dimensional array of strings. Each string is one
//   of the arguments passed to the program.
/// @param userInput string storage for user input
/// @param infile ifstream
/// @return userInput string
std::string getFileName(int argc, char **argv, std::string &userInput, std::ifstream &infile) {
    userInput = {};
    /// @brief I am a mac user and not familiar with command line prompts
    /// I got this from a geeks for geeks post
    /// if more than one argument is passed use it.
    if (argc > 1) { userInput = argv[1]; }
        /// else get input from user do/while to continue until valid file is found.
    else {
        do {// until file is found
            std::cout << "Please enter your file name: " << std::endl
                      << "\x1b[32m> \x1b[0m";
            std::cin >> userInput;
            //userInput = makeLowerCase(userInput);
            infile.open(userInput);
            if (!infile || infile.fail()) {
                std::cout << "I could not fine your file." << std::endl
                          << "Please, try again." << std::endl;
                continue;
            }
            break;
        } while (true);

    }///# else
    return std::string(userInput);
}///# getFileName

/// @brief This function checks to see if the user wants to
///        run the program again
/// @return capitalized user input
bool loopProgram() {
    std::cout << "\nAnother sublist? (y/n)" << std::endl;
    std::cout << "\x1b[32m> \x1b[0m";
    std::string userInput;
    std::cin >> userInput;
    userInput = makeLowerCase(userInput);
    return userInput == "y" ? true : false;
}///#loopProgram

std::string makeLowerCase(const std::string &in) {
    std::string out;
    std::transform(in.begin(), in.end(), std::back_inserter(out), ::tolower);
    return out;
}///#makeLowerCase

