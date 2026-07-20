class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        // with using division this is the sol
        int n = (int)a.size();
        int p = 1, q = 1;
        for (int i = 0; i < n; i++) {
            p *= a[i];
            if (a[i] != 0) q *= a[i];
        }
        vector<int> ans(n);
        int cnt = count(a.begin(), a.end(), 0);
        if (cnt > 1) {
            return ans;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) ans[i] = q;
            else ans[i] = p/a[i];
        }
        return ans;
    }
};
