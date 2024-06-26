from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix=""
        if len(strs)==0: return prefix

        for i in range(len(min(strs))):
            c=strs[0][i]
            if all(a[i]==c for a in strs):
                prefix+=c
            else:
                break
        return prefix

if __name__ == '__main__':
    strs = ["flower","flow","flight"]
    result = Solution().longestCommonPrefix(strs)
    print(result)