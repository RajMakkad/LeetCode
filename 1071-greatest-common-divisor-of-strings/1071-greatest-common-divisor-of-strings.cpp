class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        int g = __gcd(n, m);
        
        if(s1 + s2 == s2 + s1)
            return s1.substr(0, g);
        
        return "";
    }
};