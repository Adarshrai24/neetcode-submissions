class Solution {
public:
    vector<int> twoSum(vector<int>& a, int req) {
        int n = (int)a.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int x = req-a[i];
            if (mp.count(x)) {
                ans.push_back(mp[x]);
                ans.push_back(i);
            }
            mp[a[i]] = i;
        }
        return ans;
    }
};
