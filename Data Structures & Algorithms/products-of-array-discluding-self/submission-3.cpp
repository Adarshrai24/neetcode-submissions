class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        // without using division this is the sol
        int n = (int)a.size();
        vector<int> pf(n), sf(n);
        pf[0] = a[0], sf[n-1] = a[n-1];
        for (int i = 1; i < n; i++) pf[i] = pf[i-1] * a[i];
        for (int i = n-2; i >= 0; i--) sf[i] = sf[i+1] * a[i];
        vector<int> ans(n);
        ans[0] = sf[1];
        ans[n-1] = pf[n-2];
        for (int i = 1; i < n-1; i++) {
            ans[i] = pf[i-1] * sf[i+1];
        }
        return ans;
    }
};
