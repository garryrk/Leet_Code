class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n + 1);
        for (auto &it : paths) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans(n + 1, -1);  

        for (int i = 1; i <= n; i++) {
            vector<bool> color_used(5, false); 
            for (auto &neighbor : adj[i]) {
                if (ans[neighbor] != -1) {
                    color_used[ans[neighbor]] = true;
                }
            }      
            for (int color = 1; color <= 4; color++) {
                if (!color_used[color]) {
                    ans[i] = color;
                    color_used[color]=true;
                    break;
                }
            }
        }
        return vector<int>(ans.begin() + 1, ans.end());
    }
};
