#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> number;
        for (int i = 0; i < nums.size(); ++i) {
            int comp = target - nums[i];
            if (number.find(nums[i]) != number.end()) {
                return { number[nums[i]], i };
            }
            number[comp] = i;
        }
        return {};  // Return an empty vector if no solution is found
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    else {
        cout << "No solution found" << endl;
    }

    return 0;
}
