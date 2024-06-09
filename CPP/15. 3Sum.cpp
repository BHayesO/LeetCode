#include <iostream>
#include <vector>
#include <algorithm>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> triplets;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 and nums[i] == nums[i - 1]) {
				continue;
			}
			int j = i + 1, k = nums.size() - 1;

			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];

				if (sum > 0) {
					k--;
				}
				else if (sum < 0) {
					j++;
				}
				else {
					vector<int> ans = { nums[i], nums[j], nums[k] };
					triplets.push_back(ans);
					j++;
				}
			}
		}

		return triplets;
	}
};

int main() {
	Solution sol;
	vector<int> nums = { -1, 0, -1, 2, -1, -4 };
	vector<vector<int>> result = sol.threeSum(nums);
	printVectorOfVectors(result);
	return 0;
}