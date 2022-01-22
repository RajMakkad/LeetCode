class Solution {
public:
    string removeKdigits(string num, int k){
        string s = "";
        for(auto &i:num){
            while(k and !s.empty() and s.back() > i){
                s.pop_back();
                k--;
            }
            if(s.empty() and i == '0') continue;
            s += i;
        }

        while(k and s.length()){
            k--;
            s.pop_back();
        }
        if(s.empty()) s += '0';

        return s; 
    }
};
