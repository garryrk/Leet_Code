class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);

        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            deg[it[0]]++;
            deg[it[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                q.push(i);
            }
        }

        int total = n;
        while (total > 2) {
            int leaves = q.size();
            total -= leaves;

            for (int i = 0; i < leaves; i++) {
                int leaf = q.front();
                q.pop();
                for (auto &it : adj[leaf]) {
                    deg[it]--;
                    if (deg[it] == 1) {
                        q.push(it);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
