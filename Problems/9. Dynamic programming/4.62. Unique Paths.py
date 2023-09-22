class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0 for i in range(n)] for _ in range(m)]

        for i in range(m):
            dp[i][0] = 1

        for i in range(n):
            dp[0][i] = 1
        
        for i in range(1, m):
            for q in range(1, n):
                dp[i][q] = dp[i-1][q] + dp[i][q-1]
        
        return dp[m-1][n-1]