class Solution {
public:
    int rob(vector<int>& a) {
        /*
        if i rob the current house I can't rob the next house
        subproblem is simple max amount money I can rob till ith house 
        dp[i][j] = max amount of money I can rob till ith house depending on
        if I rob the current house or not 
        dp[i][0] = max(dp[i-1][0], dp[i-1][1])
        dp[i][1] = dp[i-1][0] + a[i]; 
        dp[0][0] = 0;
        dp[0][1] = a[0]
        */
        int n = (int)a.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][1] = a[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + a[i];
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};
