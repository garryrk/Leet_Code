class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        cnt = [0] * 26
        n, m = len(s1), len(s2)
        
        
        if n != m:
            return False
        
       
        for ch in s1:
            cnt[ord(ch) - ord('a')] += 1
        for ch in s2:
            cnt[ord(ch) - ord('a')] -= 1
        
       
        for it in cnt:
            if it != 0:
                return False
        
       
        mismatch_count = 0
        for i in range(n):
            if s1[i] != s2[i]:
                mismatch_count += 1
            
            
            if mismatch_count > 2:
                return False

        return True
