class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        summ=nums[0]
        ans=nums[0]
        n=len(nums)
        for i in range(1,n):
            if(nums[i]>nums[i-1]):
                summ+=nums[i]
            else:
                summ=nums[i]
            ans=max(summ,ans)
        return ans
