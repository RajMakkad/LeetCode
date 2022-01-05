class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int buying_date = 0;
        int selling_date = 0;

        for(int i = 1;i<n;i++){
            if(prices[i]>=prices[selling_date]) selling_date++;
            else{
                max_profit += prices[selling_date] - prices[buying_date];
                buying_date = selling_date = i;
            }
        }
        
        max_profit += prices[selling_date] - prices[buying_date];
        return max_profit;
    }
};