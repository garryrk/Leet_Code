class Solution:
    def findMaxFish(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        visited = [[False] * m for _ in range(n)]
        ans = 0
        def dfs(i, j):
            nonlocal count
            if i < 0 or i >= n or j < 0 or j >= m or visited[i][j] or grid[i][j] == 0:
                return
            visited[i][j] = True
            count += grid[i][j]
            dfs(i + 1, j)
            dfs(i - 1, j)
            dfs(i, j + 1)
            dfs(i, j - 1)
        for i in range(n):
            for j in range(m):
                if not visited[i][j] and grid[i][j] != 0:
                    count = 0
                    dfs(i, j)
                    ans = max(ans, count)  
        
        return ans
