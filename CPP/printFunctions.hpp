// printFunctions.hpp
#ifndef PRINTFUNCTIONS_HPP
#define PRINTFUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <string>

// Function declarations
void printVector(const std::vector<int>& vec);
void printVector(const std::vector<std::string>& vec);
void printVectorOfVectors(const std::vector<std::vector<int>>& vecOfVecs);

#endif // PRINTFUNCTIONS_HPP