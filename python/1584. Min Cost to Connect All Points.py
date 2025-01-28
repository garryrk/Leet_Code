class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n=len(points)
        edge_used=0
        res=0
        visited=[False]*n
        dis=[float('inf')]*n
        dis[0]=0

        while edge_used<n:
            cur_edge=float('inf')
            cur_node=-1
            for i in range(n):
                if not visited[i] and cur_edge>dis[i]:
                    cur_edge=dis[i]
                    cur_node=i
            visited[cur_node]=True
            res+=cur_edge
            edge_used+=1

            for i in range(n):
                cost=abs(points[i][0]-points[cur_node][0])+abs(points[i][1]-points[cur_node][1])
                if not visited[i] and cost<dis[i]:
                    dis[i]=cost
        
        return res
