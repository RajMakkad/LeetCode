class Solution {
    unordered_set<string> st;
    int ans = 0;
    void backtrack(int idx,string &s){
        int n = s.length();
        if(idx >= n){
            ans = max(ans,(int)st.size());
            return ;
        }

        string sub = "";
        for(int i = idx;i<n;i++){
            sub += s[i];
            if(st.find(sub) == st.end()){
                st.insert(sub);
                backtrack(i + 1,s);
                st.erase(sub);
            }
        }
    }
public:
    int maxUniqueSplit(string s){
        backtrack(0,s);
        return ans;
    }
};