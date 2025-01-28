class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        adj=[[] for _ in range(n)]
        for edge in roads:
            u,v,w = edge
            adj[u].append((w,v))
            adj[v].append((w,u))

        mod=10**9+7
        dis=[float('inf')]*n
        ways=[0]*n
        dis[0]=0
        ways[0]=1

        pq=[]
        heapq.heappush(pq,(0,0))
        while pq:
            dis1,node=heapq.heappop(pq)

            for adjW,adjNode in adj[node]:
                if(adjW+dis1<dis[adjNode]):
                    dis[adjNode]=adjW+dis1
                    heapq.heappush(pq,(dis[adjNode],adjNode))
                    ways[adjNode]=ways[node]%mod
                
                elif(adjW+dis1==dis[adjNode]):
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod
        
        return ways[n-1]%mod



