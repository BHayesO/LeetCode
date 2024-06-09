#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		vector<char> stack;
		string left = "{[(";
		map<char, char> right = { {'}','{'},{']','['},{')','('} };

		for (char ch : s) {
			if ( left.find(ch)!=string::npos) {
				stack.push_back(ch);
			}
			else if (right.find(ch)!=right.end()) {
				if (!stack.empty() && right[ch] == stack.back()) {
					stack.pop_back();
				}
				else {
					return false;
				}
			}
		}
		return stack.empty();
	}
};

int main() {
	Solution sol;
	string s = "{[()]}";
	bool result = sol.isValid(s);
	printBoolean(result);
	return 0;
}