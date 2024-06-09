#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int> nums, int target) {
		if (nums.size() < 4) {
			return {};
		}
		sort(nums.begin(), nums.end());
		vector<vector<int>> combinations;
		for (size_t i=0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (size_t j = nums.size()-1; j > i + 2;j--) {
				if (j < nums.size() - 1 && nums[j] == nums[j + 1]) continue;
				int left = i + 1, right = j - 1;
				while (right > left) {
					int total = nums[i] + nums[left] + nums[right] + nums[j];
					if (total > target) {
						right--;
					}
					else if (total < target) {
						left++;
					}
					else {
						vector<int> combination = { nums[i],nums[left],nums[right],nums[j] };
						if (find(combinations.begin(), combinations.end(), combination) == combinations.end()) {
							combinations.push_back(combination);
						}
						right--;
					}
				}
			}
		}
		return combinations;
	}
};

int main() {
	Solution sol;
	vector<int> nums = { 1,0,-1,0,-2,2 };
	int target = 0;
	printVectorOfVectors(sol.fourSum(nums, target));
}