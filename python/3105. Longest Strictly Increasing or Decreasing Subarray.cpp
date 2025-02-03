class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        cnt=1
        n=len(nums)
        maxx=1
        for i in range(1,n):
            if nums[i]>nums[i-1]:
                cnt+=1
                maxx=max(cnt,maxx)
            else:
                cnt=1
        cnt=1

        for i in range(1,n):
            if nums[i]<nums[i-1]:
                cnt+=1
                maxx=max(cnt,maxx)
            else:
                cnt=1
        return maxx
