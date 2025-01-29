class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        dp=[[-1]*2 for _ in range(n)]

        def solve(ind,buy):
            if ind>=n:
                return 0
            if dp[ind][buy]!=-1:
                return dp[ind][buy]
            ans=0
            if(buy==0):
                ans=max(-prices[ind]+solve(ind+1,1),solve(ind+1,0))
            else:
                ans=max(prices[ind]+solve(ind+2,0),solve(ind+1,1))
            
            dp[ind][buy]=ans
            return ans
        
        return solve(0,0)
