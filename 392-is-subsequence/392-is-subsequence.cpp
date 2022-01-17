class Solution {
public:
    bool isSubsequence(string s, string t){
        int n = t.length();
        int m = s.length();
        int in = 0;
        
        for(int i = 0;i<n;i++){
            if(s[in] == t[i]) in++;
            if(in == m) break;
        }
        
        return in == m;
    }
};