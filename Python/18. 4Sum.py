from typing import List

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return []
        nums.sort()
        combinations = []
        for i in range(0,len(nums)-3,1):
            for j in range(len(nums)-1,i+2,-1):
                left = i+1
                right = j-1
                while right>left:
                    total = nums[i]+nums[j]+nums[left]+nums[right]
                    if total>target:
                        right-=1
                    elif total<target:
                        left+=1
                    else:
                        combination = [nums[i],nums[left],nums[right],nums[j]]
                        if combination not in combinations:
                            combinations.append(combination)
                        right-=1
        return combinations
                            

if __name__ == "__main__":
    nums = [1,0,-1,0,-2,2]
    target = 0
    result = Solution().fourSum(nums,target)
    print(result)