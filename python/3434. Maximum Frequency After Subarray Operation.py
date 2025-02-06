class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        ori=nums.count(k)
        res=0
        for m in range(1,51):
            if m==k:
                continue
            cur=0
            mx=0
            for n in nums:
                if n==m:
                    cur+=1
                elif n==k:
                    cur-=1
                cur=max(cur,0)
                mx=max(cur,mx)
            res=max(res,mx)
        return ori+res
