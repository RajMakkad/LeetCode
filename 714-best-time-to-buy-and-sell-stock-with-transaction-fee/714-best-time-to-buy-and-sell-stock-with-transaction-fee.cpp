class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buying_state = -prices[0]; 
        int selling_profit = 0;
        int profit_after_fee = 0;
        
        for(int i = 1;i<n;i++){
            selling_profit = max(selling_profit,prices[i] + buying_state);
            buying_state = max(buying_state,profit_after_fee - prices[i]);
            profit_after_fee = max(profit_after_fee,selling_profit - fee);
        }
        
        return profit_after_fee;
    }
};