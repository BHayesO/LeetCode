#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<int,unordered_map<int,bool>> memo;
        
        function<bool(int, int)> dp = [&](int i, int j) {
            if (memo.find(i) != memo.end() && memo[i].find(j) != memo[i].end()) {
                return memo[i][j];
            }
            
            bool ans;
            if (j == p.size()) {
                ans = (i == s.size());
            }
            else {
                bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    ans = (dp(i, j + 2) || (first_match && dp(i + 1, j)));
                }
                else {
                    ans = first_match && dp(i + 1, j + 1);
                }
            }
            memo[i][j] = ans;
            return ans;
        };
        return dp(0, 0);
    }
};

int main() {
    Solution sol;
    string s = "aa";
    string p = "a*";
    cout << sol.isMatch(s, p) << endl;
}