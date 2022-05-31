class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int n = s.length();

        for(int i = 0;i + k <= n;i++){
            st.insert(s.substr(i,k));
        }

        int x = 1<<k;
        return (int)st.size() == x;
    }
};