// printFunctions.hpp
#ifndef PRINTFUNCTIONS_HPP
#define PRINTFUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Structures.hpp"

// Function declarations
void printVector(const std::vector<int>& vec);
void printVector(const std::vector<std::string>& vec);
void printVector(const std::vector<ListNode*>& vec);
void printVectorOfVectors(const std::vector<std::vector<int>>& vecOfVecs);
void printListNode(const ListNode* head);
void printBoolean(const bool boolean);

#endif // PRINTFUNCTIONS_HPP