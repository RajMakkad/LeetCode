class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0;
        while(i < n and j < m){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else 
                i++;
        }
        return m - j;
    }
};