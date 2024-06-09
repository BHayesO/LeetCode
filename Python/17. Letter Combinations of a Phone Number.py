from typing import List

class Solution:
    def letterCombination(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        
        map = {'2':'abc','3':'def','4':'ghi','5':'jkl',
               '6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        
        combinations = ['']
        
        for digit in digits:
            temp = []
            if digit in map:
                for comb in combinations:
                    for char in map[digit]:
                        temp.append(comb+char)
            combinations = temp


if __name__ == '__main__':
    digits = '23'
    result = Solution().letterCombination(digits)
    print(result)