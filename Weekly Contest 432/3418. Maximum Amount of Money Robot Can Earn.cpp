class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1)));
        
        function<int(int, int, int)> solve = [&](int i, int j, int k) -> int {
            if (i >= n || j >= m) return INT_MIN;
            if (i == n-1 && j == m-1) {
     
                if (coins[i][j] < 0 && k > 0) return 0;
                return coins[i][j]; 
            }
            if (dp[i][j][k] != -1) return dp[i][j][k]; 
            
            int take = INT_MIN, not_take = INT_MIN;
    
            take = coins[i][j] + max(solve(i + 1, j, k), solve(i, j + 1, k));
            
          
            if (coins[i][j] < 0 && k > 0) {
                not_take = max(solve(i + 1, j, k - 1), solve(i, j + 1, k - 1));
            }

            return dp[i][j][k] = max(take, not_take);
        };

        return solve(0, 0, 2); 
    }
};
