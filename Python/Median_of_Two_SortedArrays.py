from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merge = []
        i,j = 0,0
        nums1_len,nums2_len = len(nums1),len(nums2)
        merge_len = nums1_len + nums2_len
        mid = merge_len//2

        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                merge.append(nums1[i])
                i+=1
            else:
                merge.append(nums2[j])
                j+=1
        while i<len(nums1):
            merge.append(nums1[i])
            i+=1
        while j<len(nums2):
            merge.append(nums2[j])
            j+=1
            
        if merge_len%2==0:
            return (merge[mid-1]+merge[mid])/2
        else:
            return merge[mid]
    ''' Solution using native functions of python (sort)
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums.sort()
        if len(nums)%2==0:
            return (nums[len(nums)//2-1]+nums[len(nums)//2])/2
        else:
            return nums[len(nums)//2]
    '''

if __name__ == "__main__":
    nums1, nums2 = [1,2], [3,4]
    result = Solution().findMedianSortedArrays(nums1,nums2)
    print(result)