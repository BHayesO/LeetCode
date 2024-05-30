#include <iostream>
#include <unordered_map>
#include <string> 

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (charIndexMap.find(s[i]) != charIndexMap.end()) {
                // Mueve el inicio de la ventana deslizante
                start = max(start, charIndexMap[s[i]] + 1);
            }
            // Actualiza el índice del carácter actual
            charIndexMap[s[i]] = i;
            // Calcula la longitud de la subcadena actual
            maxLength = max(maxLength, i - start + 1);
        }

        return maxLength;
    }
};

int main() {
    string s = "pwwkew";
    Solution sol;
    int length = sol.lengthOfLongestSubstring(s);
    cout << length << endl;
    return 0;
}