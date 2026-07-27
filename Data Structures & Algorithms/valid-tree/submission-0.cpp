class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // just need to check if all nodes are connected and 
        // there is no cycle formed that's it
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n);
        bool ok = false;
        auto dfs = [&] (auto&& self, int u, int p) -> void {
            vis[u] = true;
            for (auto v : adj[u]) {
                if (vis[v]) {
                    if (v != p) {
                        ok = true;
                    }
                    continue;
                }
                self(self, v, u);
            }
        };

        dfs(dfs, 0, -1);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }
        if (ok) return false;
        return true;
    }
};
