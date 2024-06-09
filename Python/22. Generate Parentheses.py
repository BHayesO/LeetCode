from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n==0:
            return [""]
        ans = []
        for i in range(n):
            for left in self.generateParenthesis(i):
                for right in self.generateParenthesis(n-1-i):
                    ans.append("("+left+")"+right)
        return ans

if __name__ == "__main__":
    n = 3
    result =  Solution().generateParenthesis(n)
    print(result)