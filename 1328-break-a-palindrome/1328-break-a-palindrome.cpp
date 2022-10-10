class Solution {
public:
    string breakPalindrome(string p) {
        int n = p.length();
        if(n == 1) return "";
        
        for(int i = 0;i < n;i++){
            if(n % 2 and i == n/2) continue;
            
            
            if(p[i] != 'a') {
                p[i] = 'a';
                return p;
            }
        }
        
        p[n - 1] = 'a';
        if(p[0] == p[n - 1]) p[n - 1] = 'b';
        
        return p;
    }
};