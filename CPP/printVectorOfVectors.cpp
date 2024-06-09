#include "printFunctions.hpp"

void printVectorOfVectors(const std::vector<std::vector<int>>& vecOfVecs) {
	std::cout << "[";
	for (size_t i = 0; i < vecOfVecs.size(); i++) {
		printVector(vecOfVecs[i]);
		if (i < vecOfVecs.size() - 1) {
			std::cout << ",";
		}
	}
	std::cout << "]";
}