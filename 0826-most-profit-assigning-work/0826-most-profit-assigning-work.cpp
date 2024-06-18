class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size(), m = worker.size();
        vector<pair<int, int>> dp(n);
        for(int i = 0; i < n; i++)
            dp[i] = {difficulty[i], profit[i]};
        dp.push_back({1e5, 0});
        sort(dp.begin(), dp.end());
        sort(worker.begin(), worker.end());
        int i = 0, j = 0, sub = 0, ans = 0;
        while(j < m){
            int d = dp[i].first;
            int p = dp[i].second;
            if(d <= worker[j]) {
                sub = max(sub, p);
                i++;
            }
            else {
                ans += sub;
                j++;
            }
        }
        return ans;
    }
};