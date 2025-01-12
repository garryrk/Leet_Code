class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int, int>> adj[n + 1];
        int maxWeight = 0;
        for (auto& it : edges) {
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<bool> vis(n + 1, false);
        
        function<int(int, int)> dfs = [&](int u, int mid) -> int {
            vis[u] = true;
            int reachableNodes = 1;
            for (auto& [v, w] : adj[u]) {
                if (!vis[v] && w <= mid) {
                    reachableNodes += dfs(v, mid);
                }
            }
            return reachableNodes;
        };
        
        int l = 1, r = 1000001, ans = -1;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            fill(vis.begin(), vis.end(), false);
            
            if (dfs(0, mid)==n) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};


//MST
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int mn=0;
        vector<int>vis(n);
        vector<vector<vector<int>>>invg(n);
        for(auto i:edges){
            invg[i[1]].push_back({i[2],i[0]}); 
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq; 
        pq.push({0,0});
        while(pq.size()){
            auto node=pq.top()[1],w=pq.top()[0];
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            mn=max(mn,w); 
            for(auto i:invg[node]){
                if(!vis[i[1]])
                pq.push(i);
            }
        }
        for(auto i:vis)if(i==0)return -1;
        return mn;  
    }
};
