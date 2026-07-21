class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for (char c : s) {
            if (st.empty() || c == '(' || c == '[' || c == '{') {
                st.push_back(c);
            } else {
                if (c == ')') {
                    if (st.back() == '(') st.pop_back();
                    else st.push_back(c);
                } else if (c == ']') {
                    if (st.back() == '[') st.pop_back();
                    else st.push_back(c);
                } else if ('}') {
                    if (st.back() == '{') st.pop_back();
                    else st.push_back(c);
                }
            }
        }
        return st.empty();
    }
};
