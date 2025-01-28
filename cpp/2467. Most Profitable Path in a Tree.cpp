
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> par(n, -1);
        vector<int> dis(n, 0);
        vector<int> adj[n];

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        function<void(int, int)> dfs = [&](int u, int p) {
            par[u] = p;
            for (auto &v : adj[u]) {
                if (v != p) {
                    dis[v] = dis[u] + 1;
                    dfs(v, u);
                }
            }
        };

        dis[0] = 0;
        dfs(0, -1);

        int cur = bob;
        int d = 0;
        while (cur != 0) {
            if (dis[cur] > d) {
                amount[cur] = 0;
            } else if (dis[cur] == d) {
                amount[cur] /= 2;
            }
            cur = par[cur];
            d++;
        }

        function<int(int, int)> dfs2 = [&](int u, int p) -> int {
            int total = INT_MIN;
            bool isLeaf = true;

            for (auto &v : adj[u]) {
                if (v != p) {
                    isLeaf = false;
                    total = max(total, dfs2(v, u));
                }
            }

            if (isLeaf) {
                return amount[u];
            }
            return amount[u] + total;
        };

        return dfs2(0, -1);
    }
};
