class Solution {
public:
    int maximumGain(string s, int x, int y) {
        pair<string, int> max_, min_;
        if(x > y){
            max_ = {"ab", x};
            min_ = {"ba", y};
        }
        else {
            max_ = {"ba", y};
            min_ = {"ab", x};
        }
            
        string stack = "";
        int ans = 0;
        for(auto &i: s){
            if(i == max_.first[1] and stack.size() > 0 and stack.back() == max_.first[0]){
                ans += max_.second;
                stack.pop_back();
            }
            else
                stack += i;
        }
        string stack2 = "";
        for(auto &i: stack){
            if(i == min_.first[1] and stack2.size() > 0 and stack2.back() == min_.first[0]){
                ans += min_.second;
                stack2.pop_back();
            }
            else
                stack2 += i;
        }
        return ans;
    }
};