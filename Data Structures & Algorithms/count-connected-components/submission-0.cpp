class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n);
        auto dfs = [&] (auto&& self, int u) -> void {
            vis[u] = true;
            for (auto v : adj[u]) {
                if (vis[v]) continue;
                self(self, v);
            }
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            ans++;
            dfs(dfs, i);
        }
        return ans;
    }
};
