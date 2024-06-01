#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int value = 0;
		map<char, int> values = { {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
		int i = 0;

		while (i < s.size() - 1) {
			if (s[i] == 'C' && (s[i+1]=='D' || s[i+1]=='M')) {
				value += (values[s[i + 1]] - values[s[i]]);
				i+=2;
			}
			else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
				value += (values[s[i + 1]] - values[s[i]]);
				i+=2;
			}
			else if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
				value += (values[s[i + 1]] - values[s[i]]);
				i+=2;
			}
			else {
				value += values[s[i]];
				i++;
			}
		}

		return value;
	}
};

int main() {
	Solution sol;
	string s = "MCMXCIV";
	cout << sol.romanToInt(s) << endl;
}