class Solution {
public:
    int coinChange(vector<int>& a, int target) {
        #define INF 1e9;
        int n = a.size();
        vector<int> dp(target+1, -1);
        dp[0] = 0;
        auto rec = [&] (auto&& self, int req) {
            if (req == 0) return 0;
            if (dp[req] != -1) return dp[req];
            int res = INF;
            for (int i = 0; i < n; i++) {
                if (a[i] > req) continue;
                res = min(res, self(self, req-a[i]) + 1);
            }
            return dp[req] = res;
        };
        rec(rec, target);
        if (dp[target] == 1e9) return -1;
        return dp[target];
    }
};
