class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buying_state = -prices[0]; 
        int selling_profit = 0;
        int old_sp = selling_profit;
        
        for(int i = 1;i<n;i++){
            old_sp = selling_profit; 
            selling_profit = max(selling_profit,prices[i] + buying_state - fee);
            buying_state = max(buying_state,old_sp - prices[i]);
        }
        
        return selling_profit;
    }
};