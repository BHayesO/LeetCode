#include "printFunctions.hpp"

void printBoolean(bool boolean) {
	if (boolean) {
		std::cout << "True" << std::endl;
	}
	else {
		std::cout << "False" << std::endl;
	}
}