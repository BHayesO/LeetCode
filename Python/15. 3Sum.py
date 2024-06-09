from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        lists = []
        nums.sort()
        
        for i, a in enumerate(nums):
            if i>0 and a==nums[i-1]:
                continue
            
            j,k = i+1, len(nums)-1
            
            while j<k:
                tsum = a + nums[j] + nums[k]
                if tsum>0:
                    k-=1
                elif tsum<0:
                    j+=1
                else:
                    lists.append([a,nums[j],nums[k]])
                    j+=1
                    while nums[j]==nums[j-1] and j<k:
                        j+=1
        
        return lists
    
if __name__ == '__main__':
    nums = [-1,0,1,2,-1,-4]
    result = Solution().threeSum(nums)
    print(result)