#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
	vector<string> letterCombination(string digits) {
		if (digits.empty()) {
			return {};
		}

		map<string, string> letters = { {"2","abc"},{"3","def"},{"4","ghi"},{"5","jkl"},
										{"6","mno"},{"7","pqrs"},{"8","tuv"},{"9","wxyz"}
		};

		vector<string> combinations = { "" };
		for (char digit : digits) {
			vector<string> temp;
			if (letters.find(string(1, digit)) != letters.end()) {
				for (const string& comb : combinations) {
					for (char character : letters[string(1, digit)]) {
						temp.push_back(comb + character);
					}
				}
			}
			combinations = temp;
		}
		return combinations;
	}
};

int main() {
	Solution sol;
	string digits = "23";
	vector<string> result = sol.letterCombination(digits);
	printVector(result);
	return 0;
}