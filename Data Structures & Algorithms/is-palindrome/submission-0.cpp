class Solution {
public:
    bool isPalindrome(string s) {
        string p = "";
        for (auto c : s) {
            if (isalnum(c)) p += tolower(c);
        }
        string q = p;
        reverse(q.begin(), q.end());
        if (p == q) return true;
        return false;
    }
};
