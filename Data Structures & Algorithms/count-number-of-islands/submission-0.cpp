class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));

        auto dfs = [&] (auto&& self, int i , int j) {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (vis[i][j]) return;
            if (grid[i][j] == '0') return;
            vis[i][j] = true;
            self(self, i, j+1);
            self(self, i, j-1);
            self(self, i+1, j);
            self(self, i-1, j);
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) continue;
                if (grid[i][j] == '0') continue;
                ans++;
                dfs(dfs, i, j);
            }
        }

        return ans;
    }
};
