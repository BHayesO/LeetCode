from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        i = 0
        prod = 0
        j = len(height)-1
        while i<j:
            prod= max(prod, (min(height[i],height[j])*(j-i)))
            if height[j]>=height[i] :
                i+=1
            else:
                j-=1
        return prod
    
if __name__ == '__main__':
    height = [1,8,6,2,5,4,8,3,7]
    result = Solution().maxArea(height)
    print(result)