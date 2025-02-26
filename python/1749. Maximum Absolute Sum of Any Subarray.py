from typing import List

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        maxSum = 0
        minSum = 0
        pref = 0

        for num in nums:
            pref += num
            maxSum = max(maxSum, pref)
            minSum = min(minSum, pref)

        return maxSum - minSum
