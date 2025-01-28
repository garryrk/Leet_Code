class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n=len(grid)
        m=len(grid[0])
        
        q=deque()
        fresh=0
        for i in range(n):
            for j in range(m):
                if grid[i][j]==2:
                    q.append((i,j))
                elif grid[i][j]==1:
                    fresh+=1
        
        q.append((-1,-1))
        dirs=[(-1,0),(0,-1),(1,0),(0,1)]
        result=-1
        while q:
            row,col=q.popleft()
            if row==-1:
                result+=1
                if(q):
                    q.append((-1,-1))
            else:
                for dx,dy in dirs:
                    x=row+dx
                    y=col+dy
                    if(x>=0 and y>=0 and x<n and y<m and grid[x][y]==1):
                        q.append((x,y))
                        grid[x][y]=0
                        fresh-=1
        
        if(fresh==0):
            return result
        else:
            return -1


            
