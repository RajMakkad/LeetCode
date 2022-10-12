class Solution {
public:
    int largestVariance(string s) {
        unordered_set<char> unique(begin(s), end(s));
        
        int ans = 0;
        for(auto i:unique){
            for(auto j:unique){
                if(i == j) continue;
                int res = 0, first_b = 0, has_b = 0;
                
                for(auto k:s){
                    res += (k == i);
                    if(k == j){
                        has_b = 1;
                        if(first_b > 0 and res >= 0){
                            first_b = 0;
                        }
                        else {
                            res--;
                            if(res < 0) {
                                res = -1;
                                first_b = 1;
                            }
                        }
                    }
                    ans = max(ans, has_b ? res : 0);
                }
            }
        }
        
        return ans;
    }
};