#include <iostream>
#include <vector>
#include <string>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if (n == 0) {
			return { "" };
		}
		vector<string> ans = {};
		for (int i = 0;i < n;i++) {
			for (string left : generateParenthesis(i)) {
				for (string right : generateParenthesis(n - 1 - i)) {
					ans.push_back("(" + left + ")" + right);
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;
	int n = 3;
	vector<string> result = sol.generateParenthesis(n);
	printVector(result);
}