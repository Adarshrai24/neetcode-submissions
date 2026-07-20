class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = (int)s.size(), m = (int)t.size();
        vector<int> f1(26), f2(26);
        for (int i = 0; i < n; i++) {
            f1[s[i]-'a']++;
        }
        for (int i = 0; i < m; i++) {
            f2[t[i]-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (f1[i] != f2[i]) {
                return false;
            }
        }
        return true;
    }
};
