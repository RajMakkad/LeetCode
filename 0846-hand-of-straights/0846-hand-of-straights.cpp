class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> dp;
        for(auto h: hand)
            dp[h]++;
        while((int)dp.size() > 0){
            int fe = dp.begin()->first;
            int Gsize = groupSize;
            while(Gsize--){
                if(dp[fe] > 0)
                    dp[fe]--;
                else 
                    return false;
                if(dp[fe] == 0)
                    dp.erase(fe);
                fe++;
            }
        }
        return true;
    }
};