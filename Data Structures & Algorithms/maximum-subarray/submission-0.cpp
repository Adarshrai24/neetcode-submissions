class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        int ans = *max_element(a.begin(), a.end());
        if (ans < 0) {
            return ans;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            ans = max(ans, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return ans;
    }
};
