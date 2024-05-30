#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool flag = false;

        if (x < 0) {
            x = abs(x);
            flag = true;
        }

        int minVal = numeric_limits<int>::min();
        int maxVal = numeric_limits<int>::max();

        int rx = 0;

        while (x > 0) {
            int rest = x % 10;

            if (rx > (maxVal - rest) / 10) {
                return 0;
            }

            rx = rx * 10 + rest;            
            x = x / 10;
        }

        if (!flag) {
            return rx;
        }

        return rx * -1;

    }
};

int main() {
    int x = 1534236469;
    Solution sol;
    cout << sol.reverse(x) << endl;
}