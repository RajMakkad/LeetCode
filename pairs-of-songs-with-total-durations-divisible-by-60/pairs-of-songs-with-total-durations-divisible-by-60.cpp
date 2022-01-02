class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60,0);
        int ans = 0;
        
        for(auto &i:time){
            ans += count[(60 - i%60)%60];
            count[i%60]++;
        }
        
        return ans;
    }
};