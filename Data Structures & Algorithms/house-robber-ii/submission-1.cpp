class Solution {
public:
    int rob(vector<int>& a) {
        int n = (int)a.size();
        if (n == 1) {
            return a[0];
        }
        vector<vector<int>> dp1(n, vector<int>(2));
        dp1[0][1] = a[0];
        for (int i = 1; i < n; i++) {
            dp1[i][0] = max(dp1[i-1][0], dp1[i-1][1]);
            if (i == 1) continue;
            dp1[i][1] = dp1[i-1][0] + a[i];
        }

        vector<vector<int>> dp(n, vector<int>(2));
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + a[i];
        }

        int x = dp1[n-1][0];
        int y = max(dp[n-1][1], dp[n-1][0]);
        //cout << x << ' ' << y << endl;
        return max(x, y);
    }
};
