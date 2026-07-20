class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        int n = (int)a.size();
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) st.insert(a[i]);
        for (int i = 0; i < n; i++) {
            if (mp.count(a[i])) continue;
            int j = a[i]+1;
            bool ok = false;
            while (st.count(j)) {
                if (mp.count(j)) {
                    mp[a[i]] = mp[j] + j - a[i];
                    ok = true;
                    break;
                } else {
                    j++;
                }
            }
            if (!ok) {
                mp[a[i]] = j - a[i];
            }
        }

        int ans = 0;
        for (auto it : mp) ans = max(ans, it.second);
        return ans;
    }
};
