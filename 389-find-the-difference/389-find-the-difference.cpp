class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        int n = t.length();
        
        for(int i = 0;i<n;i++){
            if(i > n - 2 || t[i] != s[i]){
                return t[i];
            }
        }
        
        return t[0];
    }
};