class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> cur;

        function<void(int)> dfs = [&](int u) {
            cur.push_back(u);
                for (auto &v : graph[u]) {
                    dfs(v);
                }
                
            if (u == n - 1) {
                res.push_back(cur);
            }
            cur.pop_back();
        };

        dfs(0);
        return res;
    }
};
