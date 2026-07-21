class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        auto rec = [&](auto&& self, int i, int j, int k) -> bool {
            if (k == word.size()) return true;

            if (i < 0 || i >= n || j < 0 || j >= m) return false;
            if (vis[i][j]) return false;
            if (board[i][j] != word[k]) return false;

            vis[i][j] = true;

            bool ok = self(self, i + 1, j, k + 1) ||
                      self(self, i - 1, j, k + 1) ||
                      self(self, i, j + 1, k + 1) ||
                      self(self, i, j - 1, k + 1);

            vis[i][j] = false;

            return ok;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rec(rec, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};