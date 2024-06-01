class Solution:
    def romanToInt(self, s: str) -> int:
        value = 0
        values = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        i = 0
        while i<len(s)-1:
            if s[i]=='C' and (s[i+1]=='D' or s[i+1]=='M'):
                value+=(values[s[i+1]]-values[s[i]])
                i+=1
            elif s[i]=='X' and (s[i+1]=='L' or s[i+1]=='C'):
                value+=(values[s[i+1]]-values[s[i]])
                i+=1
            elif s[i]=='I' and (s[i+1]=='V' or s[i+1]=='X'):
                value+=(values[s[i+1]]-values[s[i]])
                i+=1
            else:
                value+=values[s[i]]
            i+=1
        try:
            value+=values[s[i]]
        except:
            pass
        return value
    
if __name__ == '__main__':
    s = 'MCMXCIV'
    result = Solution().romanToInt(s)
    print(result)