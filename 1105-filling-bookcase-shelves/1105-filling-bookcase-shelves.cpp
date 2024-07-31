class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = books[0][1];
        for(int i = 2; i <= n; i++) {
            int w = books[i - 1][0];
            int max_ = books[i - 1][1];
            for(int j = i - 1; j >= 0; j--) {
                if(w > shelfWidth)
                    break;
                dp[i] = min(dp[i], max_ + dp[j]);
                if(j > 0){
                    w += books[j - 1][0];
                    max_ = max(max_, books[j - 1][1]);
                }
            }
        }
        return dp[n];
    }
};