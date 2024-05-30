#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s == string(s.rbegin(), s.rend())) return s;

        int start = 0, size = 1;

        for (int i = 1; i < s.size(); ++i) {
            int l = i - size, r = i + 1;
            string s1 = (l >= 1) ? s.substr(l - 1, r - l + 1) : "";

            if (l >= 1 && s1 == string(s1.rbegin(), s1.rend())) {
                size += 2;
                start = l - 1;
            }
            else {
                string s2 = s.substr(l, r - l);
                if (s2 == string(s2.rbegin(), s2.rend())) {
                    size += 1;
                    start = l;
                }
            }
        }

        return s.substr(start, size);
    }
};

int main() {
	Solution sol;
	string s = "aabaabbabababaabababa";
	cout << sol.longestPalindrome(s) << endl;
	return 0;
}