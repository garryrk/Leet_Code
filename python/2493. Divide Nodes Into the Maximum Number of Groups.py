

class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n+1)]
        
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        def bipartite():
            color = [-1] * (n+1)
            for i in range(1, n+1):
                if color[i] == -1:
                    q = deque([i])
                    color[i] = 1
                    while q:
                        cur = q.popleft()
                        for child in adj[cur]:
                            if color[child] == -1:
                                color[child] = 1 - color[cur]
                                q.append(child)
                            elif color[child] == color[cur]:
                                return False
            return True

        if not bipartite():
            return -1

        def findFarthestDistBFS(src):
            vis = [-1] * (n+1)
            vis[src] = 1
            cnt = 0
            q = deque([src])
            
            while q:
                sz = len(q)
                cnt += 1
                for _ in range(sz):
                    node = q.popleft()
                    for v in adj[node]:
                        if vis[v] == -1:
                            vis[v] = 1
                            q.append(v)
            return cnt

        dis = [-1] * (n+1)
        for i in range(1, n+1):
            dis[i] = findFarthestDistBFS(i)

        def solve(u, vis):
            vis[u] = 1
            maxi = dis[u]
            for v in adj[u]:
                if vis[v] == -1:
                    maxi = max(maxi, solve(v, vis))
            return maxi

        vis = [-1] * (n+1)
        ans = 0

        for i in range(1, n+1):
            if vis[i] == -1:
                ans += solve(i, vis)
        
        return ans
