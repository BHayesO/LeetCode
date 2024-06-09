from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        closest = (10000,0)
        for i,a in enumerate(nums):
            j,k = i+1,len(nums)-1
            while j<k:
                tsum = a + nums[j] + nums[k]
                sumdistance = tsum-target
                if abs(sumdistance)<closest[0]:
                    closest = (abs(sumdistance),tsum)
                    if sumdistance<0:
                        j+=1
                    elif sumdistance>0:
                        k-=1
                    else:
                        return tsum
                else:
                    if sumdistance<0:
                        j+=1
                    elif sumdistance>0:
                        k-=1

        return closest[1]
    
if __name__ == "__main__":
    nums = [-1,2,1,-4]
    target = 1
    result = Solution().threeSumClosest(nums=nums,target=target)
    print(result)