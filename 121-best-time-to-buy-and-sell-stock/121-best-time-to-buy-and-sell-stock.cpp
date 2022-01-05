class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = 1e5;
        int max_profit = 0;
        
        for(auto i:prices){
            min_price = min(min_price,i);
            max_profit = max(max_profit,i - min_price);
        }
        
        return max_profit;
    }
};