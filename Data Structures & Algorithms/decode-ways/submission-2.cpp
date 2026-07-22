class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        // we can group at most 2 digits together that's it 
        // based on this fact we should make our state
        if (s[0] == '0') {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        vector<int> dp(n);
        dp[0] = 1;
        int x = (s[0] - '0') * 10 + (s[1] - '0');
        if (x <= 26 && x > 0) {
            dp[1] = 1;
        }
        if (s[1] != '0') dp[1]++;
        for (int i = 2; i < n; i++) {
            int num = (s[i-1] - '0') * 10 + (s[i] - '0');
            if (s[i] == '0') {
                if (num > 26 || num < 1) {
                    return 0;
                }
                dp[i] = dp[i-2];
            } else {
                dp[i] = dp[i-1];
                if (num <= 26 && s[i-1] != '0') {
                    dp[i] += dp[i-2];
                }
            }
        }
        return dp[n-1];
    }
};
