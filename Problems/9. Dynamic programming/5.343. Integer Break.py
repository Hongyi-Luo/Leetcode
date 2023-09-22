class Solution:
    def integerBreak(self, n: int) -> int:
        if n==2:
            return 1
        dp = [0] * (n+1)
        dp[2] = 1
        for i in range(3, n+1):
            for q in range(2, i+1):
                dp[i] = max(q * (i-q), q * dp[i-q], dp[i])

        return dp[n]