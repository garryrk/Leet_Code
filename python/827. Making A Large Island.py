class DisjointSet:
    def __init__(self, n):
        self.par = list(range(n))
        self.rank = [1] * n
        self.size = [1] * n

    def findP(self, n):
        if self.par[n] != n:
            self.par[n] = self.findP(self.par[n])
        return self.par[n]

    def Union(self, n1, n2):
        p1 = self.findP(n1)
        p2 = self.findP(n2)
        if p1 == p2:
            return
        if self.rank[p1] > self.rank[p2]:
            self.par[p2] = p1
            self.size[p1] += self.size[p2]
        else:
            self.par[p1] = p2
            self.size[p2] += self.size[p1]
            if self.rank[p1] == self.rank[p2]:
                self.rank[p2] += 1

class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        ds = DisjointSet(n * n)
        direction = [[0, 1], [1, 0], [-1, 0], [0, -1]]

        def isValid(i, j):
            return 0 <= i < n and 0 <= j < n

        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    for dr in direction:
                        newx = i + dr[0]
                        newy = j + dr[1]
                        if isValid(newx, newy) and grid[newx][newy] == 1:
                            node = (i * n) + j
                            adjNode = (newx * n) + newy
                            ds.Union(node, adjNode)

        maxx = 0
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    continue
                else:
                    sett = set()
                    for dr in direction:
                        newx = i + dr[0]
                        newy = j + dr[1]
                        if isValid(newx, newy) and grid[newx][newy] == 1:
                            node = (newx * n) + newy
                            sett.add(ds.findP(node))

                    sizee = 1
                    for it in sett:
                        sizee += ds.size[it]

                    maxx = max(maxx, sizee)

        for i in range(n * n):
            maxx = max(maxx, ds.size[ds.findP(i)])

        return maxx
