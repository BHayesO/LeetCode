from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        number = {}
        idx = 0
        for num in nums:
            comp = target-num
            if num in number:
                return [number[num],idx]
            number[comp] = idx
            idx+=1

if __name__ == "__main__":
    sol = Solution()
    result = sol.twoSum([2,7,11,15],9)
    print(result)