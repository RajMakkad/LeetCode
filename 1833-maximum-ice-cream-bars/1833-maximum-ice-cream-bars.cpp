class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        
        int ans = 0;
        for(auto &i: costs){
            if(coins >= i){
                coins -= i;
                ans++;
            }
        }
        
        return ans;
    }
};