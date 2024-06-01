#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix = "";
		if (strs.size() == 0) {
			return prefix;
		}

		auto minIt = min_element(strs.begin(), strs.end(),
								[](const string& a, const string& b) {
									return a.size() < b.size();
								});

		string shorttestStr = *minIt;
		for (int i = 0; i < shorttestStr.size(); i++) {
			char currentChar = shorttestStr[i];

			for (const string& str : strs) {
				if (str[i] != currentChar) {
					return prefix;
				}
			}

			prefix += currentChar;
		}
	}
};

int main() {
	Solution sol;
	vector<string> strs = { "flower","flow","fligth" };
	cout << sol.longestCommonPrefix(strs) << endl;
}