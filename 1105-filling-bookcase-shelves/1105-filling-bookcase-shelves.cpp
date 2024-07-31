class Solution {
    int memoization(int idx, int n, int shelfWidth, vector<vector<int>> &books, vector<int> &dp){
        if(idx == n)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int ans = INT_MAX;
        int max_ = 0;
        int w = 0;
        for(int i = idx; i < n; i++){
            if(books[i][0] + w <= shelfWidth){
                max_ = max(max_, books[i][1]);
                w += books[i][0];
                ans = min(ans, max_ + memoization(i + 1, n, shelfWidth, books, dp));
            }
            else 
                break;
        }
        return dp[idx] = ans;
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, -1);
        return memoization(0, n, shelfWidth, books, dp);
    }
};