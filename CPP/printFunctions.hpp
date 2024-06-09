// printFunctions.hpp
#ifndef PRINTFUNCTIONS_HPP
#define PRINTFUNCTIONS_HPP

#include <iostream>
#include <vector>
#include <string>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Function declarations
void printVector(const std::vector<int>& vec);
void printVector(const std::vector<std::string>& vec);
void printVectorOfVectors(const std::vector<std::vector<int>>& vecOfVecs);
void printListNode(const ListNode* head);

#endif // PRINTFUNCTIONS_HPP