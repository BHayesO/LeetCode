class Solution:
    def myAtoi(self, s: str) -> int:
        res  = ''
        sign = ''
        for i in s:
            if i.isalpha():
                break
            if i == ' ':
                if len(res):
                    break
                if sign!='':
                    return 0
                continue
            if (i=='+' or i=='-'):
                if sign!='' or len(res):
                    break
                elif sign=='':
                    sign=i
                    continue
            res+=i
        try:
            k = int(float(sign+res))
            return max(-2**31,min(k,2**31-1))
        except:
            return 0
        
if __name__ == '__main__':
    s = 'words and 987'
    result = Solution().myAtoi(s)
    print(result)