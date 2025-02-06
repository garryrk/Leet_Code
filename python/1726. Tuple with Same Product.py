from collections import defaultdict

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        n=len(nums)

        #mp={}
        mp=defaultdict(int)
        total=0

        for i in range(n):
            for j in range(i + 1, n):
                mp[nums[i] * nums[j]] += 1
        
        for value,freq in mp.items():
            no_of_pairs=(freq*(freq-1))//2
            total+=(8*no_of_pairs)
        return total
