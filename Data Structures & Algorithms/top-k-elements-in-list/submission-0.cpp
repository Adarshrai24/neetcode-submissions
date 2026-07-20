class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        int n = (int)a.size();
        map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }
        vector<pair<int,int>> b;
        for (auto it : mp) {
            b.push_back({it.second, it.first});
        }
        sort(b.rbegin(), b.rend());
        
        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(b[i].second);
        return ans;
    }
};
