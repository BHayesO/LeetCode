#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x){
		string sx = to_string(x);
		string rsx = sx;
		reverse(rsx.begin(), rsx.end());
		return sx == rsx;
	}
};

int main() {
	Solution sol;
	int x = -121;
	cout << sol.isPalindrome(x) << endl;
}