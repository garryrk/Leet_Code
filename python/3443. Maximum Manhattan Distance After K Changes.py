class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        dir=[('N','E'),('N','W'),('S','E'),('S','W')]
        n=len(s)
        ans=0
        for d in dir:
            cnt,t=0,k
            for i in range(n):
                if s[i]==d[0] or s[i]==d[1]:
                    if t>0:
                        cnt+=1
                        t-=1
                    else:
                        cnt-=1
                else:
                    cnt+=1
                ans=max(ans,cnt)
        return ans
