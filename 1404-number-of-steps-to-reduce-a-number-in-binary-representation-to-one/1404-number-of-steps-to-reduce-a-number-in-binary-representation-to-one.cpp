class Solution {
    void convertToEven(string &s){
        int idx = (int)s.length() - 1;
        while(idx >= 0 and s[idx] == '1')
            s[idx--] = '0';
        if(idx >= 0)
            s[idx] = '1';
        else
            s = '1' + s;
    }
public:
    int numSteps(string s) {
        int ans = 0;
        while(s != "1"){
            if(s.back() == '0')
                s.pop_back();
            else
                convertToEven(s);
            ans++;
        }
        return ans;
    }
};