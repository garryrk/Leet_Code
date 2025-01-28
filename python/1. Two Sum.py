class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapp={}
        for i,val in enumerate(nums):
            diff=target-val
            if diff in mapp:
                return [mapp[diff],i]
            mapp[val]=i
