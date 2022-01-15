class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> p(n,vector<bool>(n,false));
        pair<int,int> ans;

        for(int len = 0;len<n;len++){
            for(int i = 0;i+len<n;i++){
                int e = i + len;
                if(len==0) p[i][e] = true;
                else if(len==1 and s[i]==s[e]) p[i][e] = true;
                else if(s[i]==s[e] and p[i+1][e-1]) p[i][e] = true;
                
                if(p[i][e]){
                    ans.first = i;
                    ans.second = len + 1;
                }
            }
        }

        return s.substr(ans.first,ans.second);
    }
};
