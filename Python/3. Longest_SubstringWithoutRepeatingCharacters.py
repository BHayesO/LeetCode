class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start,longest = 0,0
        usedCharacters = {}

        for i in range(len(s)-1):
            print(usedCharacters)
            if s[i] in usedCharacters and start <= usedCharacters[s[i]]:
                start = usedCharacters[s[i]] + 1
            else:
                longest = max(longest, i - start + 1)
            usedCharacters[s[i]] = i
        
        return longest

# Example usage:
if __name__ == "__main__":
    s = "pwwkew"
    result = Solution().lengthOfLongestSubstring(s)
    print(result)
