#include "printFunctions.hpp"

void printVector(const std::vector<int>& vec) {
	std::cout << "[";
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i];
		if (i < vec.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]";
}

void printVector(const std::vector<std::string>& vec) {
	std::cout << "[";
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i];
		if (i < vec.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "]";
}