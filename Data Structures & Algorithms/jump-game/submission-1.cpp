class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        if (n == 1) {
            return true;
        }
        if (a[0] == 0) {
            return false;
        }
        int left = 0, sum = 0;
        for (int i = 0; i < n-1; i++) {
            left--;
            left = max(left, a[i]);
            if (left == 0 && a[i] == 0) {
                return false;
            }
        }
        return true;
    }
};
