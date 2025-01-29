class DSU:
    def __init__(self, n):
        self.parent = list(range(n + 1))
        self.rank = [1] * (n + 1)
    
    def findP(self, n):
        if self.parent[n] != n:
            self.parent[n] = self.findP(self.parent[n])
        return self.parent[n]
    
    def Union(self, n1, n2):
        p1 = self.findP(n1)
        p2 = self.findP(n2)
        
        if p1 == p2:
            return False
        
        if self.rank[p1] >= self.rank[p2]:
            self.parent[p2] = p1
            self.rank[p1] += self.rank[p2]
        else:
            self.parent[p1] = p2
            self.rank[p2] += self.rank[p1]
        
        return True

class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges) + 1
        dsu = DSU(n)
        res = []
        
        for u, v in edges:
            if not dsu.Union(u, v):
                res.append(u)
                res.append(v)
                break
        
        return res
