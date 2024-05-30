#include <iostream>
#include <string>
#include <cctype>
#include <climits>

using namespace std;

class Solution {
public:
	int myAtoi(string s) {
		string res = "", sign = "";
		bool hasSign = false, hasNumber = false;

		for (char c : s) {
			if (isalpha(c)) {
				break;
			}
			if (isspace(c)) {
				if (hasNumber) {
					break;
				}
				if (hasSign) {
					return 0;
				}
				continue;
			}
			if (c == '+' || c == '-') {
				if (hasNumber || hasSign) {
					break;
				}
				else if(!hasSign){
					sign = c;
					hasSign = true;
					continue;
				}
			}
			if (isdigit(c)) {
				res += c;
				hasNumber = true;
			}
		}
		long long result = 0;

		for (char c : res) {
			result = result * 10 + (c - '0');
			if (sign == "-" && -result < INT_MIN) {
				return INT_MIN;
			}
			if (sign == "+" && result > INT_MAX) {
				return INT_MAX;
			}
		}

		result = (sign == "-") ? -result : result;

		if (result < INT_MIN) {
			return INT_MIN;
		}
		if (result > INT_MAX) {
			return INT_MAX;
		}

		return static_cast<int>(result);
	}
};

int main() {
	string s = "123456456789";
	Solution sol;
	cout << sol.myAtoi(s) << endl;
	return 0;
}