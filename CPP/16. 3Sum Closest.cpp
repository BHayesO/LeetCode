#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> nums, int target) {
		sort(nums.begin(), nums.end());
		pair<int, int> closest = { 10000,0 };

		for (size_t i = 0; i < nums.size(); i++) {
			size_t j = i + 1, k = nums.size() - 1;
			while (j < k) {
				int tsum = nums[i] + nums[j] + nums[k];
				int sumdistance = tsum - target;
				if (abs(sumdistance) < closest.first) {
					closest = { abs(sumdistance),tsum };
				}
				if (sumdistance < 0) {
					j++;
				}
				else if(sumdistance > 0) {
					k--;
				}
				else {
					return tsum;
				}
			}
		}
			return closest.second;
	}
};

int main() {
	Solution sol;
	vector<int> nums = { -1, 2, 1, -4 };
	int target = 1;
	cout << sol.threeSumClosest(nums, target) << endl;
	return 0;
}