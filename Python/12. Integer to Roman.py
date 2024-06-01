class Solution:
    def intToRoman(self, num: int) -> str:
        roman = ''
        reversed = 0
        i = 0
        while i<=3:
            reversed = reversed*10 + num%10
            num = num//10
            i += 1
            
        val = {0:{1:'I',2:'II',3:'III',4:'IV',5:'V',6:'VI',7:'VII',8:'VIII',9:'IX'},
               1:{1:'X',2:'XX',3:'XXX',4:'XL',5:'L',6:'LX',7:'LXX',8:'LXXX',9:'XC'},
               2:{1:'C',2:'CC',3:'CCC',4:'CD',5:'D',6:'DC',7:'DCC',8:'DCCC',9:'CM'},
               3:{1:'M',2:'MM',3:'MMM'}}
        
        while reversed > 0:
            i -= 1
            totransform = reversed%10
            reversed = reversed//10
            if totransform in val[i]:
                roman += f'{val[i][totransform]}'
        return roman
    
if __name__ == '__main__':
    num = 1994
    result = Solution().intToRoman(num)
    print(result)