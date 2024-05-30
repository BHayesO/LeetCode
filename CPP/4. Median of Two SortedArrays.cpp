#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i = 0, j = 0;
        int nums1_len = nums1.size(), nums2_len = nums2.size();
        int merge_len = nums1_len + nums2_len;
        int mid = merge_len / 2;

        // Merge the two sorted arrays
        while (i < nums1_len && j < nums2_len) {
            if (nums1[i] < nums2[j]) {
                merge.push_back(nums1[i]);
                i++;
            }
            else {
                merge.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1_len) {
            merge.push_back(nums1[i]);
            i++;
        }
        while (j < nums2_len) {
            merge.push_back(nums2[j]);
            j++;
        }

        // Calculate the median
        if (merge_len % 2 == 0) {
            return (merge[mid - 1] + merge[mid]) / 2.0;
        }
        else {
            return merge[mid];
        }
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = { 1, 3 };
    vector<int> nums2 = { 2 };

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = { 1, 2 };
    vector<int> nums4 = { 3, 4 };

    cout << sol.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}