class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n = s.length();

        for(int i = 0;i<n;i++){
            if(st.empty()) st.push({s[i],1});
            else{
                if(s[i] == st.top().first){
                    auto u = st.top();
                    st.pop();
                    if(u.second + 1 == k) continue;
                    st.push({u.first,u.second + 1});
                }
                else st.push({s[i],1});
            }
        }

        string ans = "";
        while(!st.empty()){
            auto u = st.top();
            st.pop();
            while(u.second--){
                ans += u.first;
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};