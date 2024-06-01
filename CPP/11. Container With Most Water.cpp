#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0;
		int j = height.size() - 1;
		int prod = 0;

		while (i < j) {
			prod = std::max<int>(prod, std::min<int>(height[i], height[j]) * (j - i));
			if (height[j] >= height[i]) {
				i++;
			}
			else {
				j--;
			}
		}

		return prod;
	}
};

int main() {
	Solution sol;
	vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	cout << sol.maxArea(height) << endl;
}
