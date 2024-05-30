class Solution:
    def reverse(self, x: int) -> int:
        rx = str(x)[::-1]
        if rx[-1] == '-':
            rx = '-'+rx[:-1]
        rx = int(rx)
        return rx if (rx >= -2**31) and (rx < 2**31) else 0

if __name__ == '__main__':
    x = 1534236469
    result = Solution().reverse(x)
    print(result)