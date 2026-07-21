class Solution {
public:
    int search(vector<int>& a, int req) {
        int n = a.size();
        int l = 0, r = n-1, ans = -1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            // check if range is still rotated?
            if (a[mid] > a[r]) {
                if (req <= a[r]) l = mid+1;
                else {
                    if (a[mid] == req) return mid;
                    if (a[mid] < req) l = mid+1;
                    else r = mid;
                }
            } else {
                // this means range is not in rotated so we do normal bs
                //cout << "Here" << ' ' << mid << endl;
                if (req > a[r]) r = mid;
                else {
                    if (a[mid] == req) return mid;
                    if (req <= a[mid]) r = mid;
                    else l = mid+1;
                }
                //cout << l << ' ' << r << endl;
            }
        }
        return (a[r] == req ? r : -1);
    }
};
