class Solution:
    def convert(self, s: str, numRows: int) -> str:
        lin = 0
        inver = 1
        out = [""]*numRows
        for i in range(len(s)):
            out[lin] += s[i]
            if numRows > 1:
                lin+=inver
                if lin==numRows-1 or lin == 0:
                    inver*=-1
        output = ""
        for j in range(len(out)):
            output += out[j]
        return output
    
if __name__ == "__main__":
    s = "PAYPALISHIRING"
    Rows = 3
    result = Solution().convert(s, Rows)
    print(result)