class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string o = "";
        string z = "";
        for(int i = 0;i < n;i++){
            if(s[i] == '1')
                o += '1';
            else
                z += '0';
        }
        o.pop_back();
        
        return o + z + '1';
    }
};