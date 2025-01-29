class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n=len(quiet)
        adj=[[] for _ in range(n)]
        for u,v in richer:
            adj[v].append(u)
        
        ans=list(range(n))

        def dfs(node):
            if(ans[node]!=node):
                return ans[node]
            for child in adj[node]:
                solve=dfs(child)
                if(quiet[solve]<quiet[ans[node]]):
                    ans[node]=solve
            return ans[node]
        
        for i in range(n):
            dfs(i)
        
        return ans


#Topo soln

class Solution:
    def loudAndRich(self, richer: List[List[int]], quiet: List[int]) -> List[int]:
        n = len(quiet)
        graph = [[] for _ in range(n)]
        indegree = [0] * n
        ans = list(range(n))
        
        for rich in richer:
            graph[rich[0]].append(rich[1])
            indegree[rich[1]] += 1
        
        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        
        while q:
            node = q.popleft()
            
            for neighbor in graph[node]:
                if quiet[ans[node]] < quiet[ans[neighbor]]:
                    ans[neighbor] = ans[node]
                
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    q.append(neighbor)
        
        return ans
