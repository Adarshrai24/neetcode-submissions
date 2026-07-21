class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        int n = a.size();
        vector<vector<int>> ans;
        vector<int> res;
        auto rec = [&] (auto&& self, int idx, int left) {
            if (left == 0) {
                ans.push_back(res);
                return;
            }
            for (int i = idx; i < n; i++) {
                if (a[i] > left) continue;
                res.push_back(a[i]);
                self(self, i, left-a[i]);
                res.pop_back();
            }
        };
        rec(rec, 0, target);
        return ans;
    }
};
