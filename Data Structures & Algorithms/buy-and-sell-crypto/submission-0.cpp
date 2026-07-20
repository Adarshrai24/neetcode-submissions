class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        int mn = INT_MAX;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};
