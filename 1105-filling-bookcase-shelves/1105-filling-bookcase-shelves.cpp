class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        dp[1] = books[0][1];
        for(int i = 2; i <= n; i++) {
            int w = 0;
            int h = 0;
            for(int j = i; j > 0; j--) {
                w += books[j - 1][0];
                h = max(h, books[j - 1][1]);
                if(w > shelfWidth)
                    break;
                dp[i] = min(dp[i], h + dp[j - 1]);
                
            }
        }
        return dp[n];
    }
};