class Solution {
public:
    int removePalindromeSub(string s) {
        string sub = s;
        reverse(sub.begin(), sub.end());
        
        if(s == sub) return 1;
        else return 2;
    }
};