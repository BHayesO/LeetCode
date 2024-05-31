class Solution:
    def isPalindrome(self, x: int) -> bool:
        sx = str(x)
        return sx == sx[::-1]

if __name__ == '__main__':
    x = -121
    result = Solution().myAtoi(x)
    print(result)