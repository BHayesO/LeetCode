#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string roman = "";
		int reversed = 0;
		int i = 0;

		while (i <= 3) {
			reversed = reversed * 10 + num % 10;
			num = num / 10;
			i++;
		}

		map<int, map<int, string>> val = {{0,{{1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5,"V"},{6,"VI"},{7,"VII"},{8,"VIII"},{9,"IX"}}},
										  {1,{{1,"X"},{2,"XX"},{3,"XXX"},{4,"XL"},{5,"L"},{6,"LX"},{7,"LXX"},{8,"LXXX"},{9,"XC"}}},
										  {2,{{1,"C"},{2,"CC"},{3,"CCC"},{4,"CD"},{5,"D"},{6,"DC"},{7,"DCC"},{8,"DCCC"},{9,"CM"}}},
										  {3,{{1,"M"},{2,"MM"},{3,"MMM"}}}};

		while (reversed > 0) {
			i--;
			int totransform = reversed % 10;
			reversed = reversed / 10;

			if (val[i].find(totransform) != val[i].end()) {
				roman = roman + val[i][totransform];
			}
		}

		return roman;
	}
};

int main() {
	Solution sol;
	int num = 1994;
	cout << sol.intToRoman(num) << endl;
}