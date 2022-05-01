class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length() - 1;
        int m = t.length() - 1;
        int c1 = 0;
        int c2 = 0;
        
        while(n >= 0 ||  m>= 0){
            c1 = 0;
            c2 = 0;
            
            while(n >= 0 and (s[n] == '#' || c1)){
                if(s[n] == '#') c1++;
                else c1--;
                n--;
            }
            
            while(m >= 0 and (t[m] == '#' || c2)){
                if(t[m] == '#') c2++;
                else c2--;
                m--;
            }
            
            if(n >= 0 and m >= 0 and s[n] == t[m]){
                n--;
                m--;
            }
            else break;
        }
        
        return (n == -1 and m == -1);
    }
};