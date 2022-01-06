class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buying_profit = -prices[0];
        int selling_profit = 0;
        int cooldown_profit = 0;
        
        for(int i = 1;i<n;i++){
            int old_sp = selling_profit;
            selling_profit = max(selling_profit,prices[i] + buying_profit);
            buying_profit = max(buying_profit,cooldown_profit - prices[i]);
            cooldown_profit = max(cooldown_profit,old_sp);
        }
        
        return selling_profit;
    }
};