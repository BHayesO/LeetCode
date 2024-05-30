#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;

        vector<string> out(min(numRows, int(s.size())));
        int lin = 0;
        int inver = 1;

        for (int i = 0; i < s.size(); ++i) {
            out[lin] += s[i];
            if (numRows > 1) {
                lin += inver;
                if (lin == numRows - 1 || lin == 0) {
                    inver *= -1;
                }
            }
        }

        string output;
        for (int i = 0; i < out.size(); ++i) {
            output += out[i];
        }
        return output;
    }
};

int main() {
	string s = "PAYPALISHIRING";
	int Rows = 3;
	Solution sol;
	cout << sol.convert(s, Rows) << endl;
}