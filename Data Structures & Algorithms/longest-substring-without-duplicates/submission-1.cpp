class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int n = (int)s.size();
        int ans = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (j < n && !st.count(s[j])) {
                st.insert(s[j]);
                j++;
            }
            ans = max(ans, j-i);
            while (i < j && st.count(s[j])) {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
