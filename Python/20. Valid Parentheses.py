class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        left = '{[('
        right = {'}':'{',']':'[',')':'('}
        
        for c in s:
            if c in left:
                stack.append(c)
            elif c in right:
                if stack and right[c] == stack[-1]:
                    stack.pop()
                else:
                    return False
        
        return True if len(stack)==0 else False

if __name__ == '__main__':
    s = '{[()]}'
    result = Solution().isValid(s)
    print(result)