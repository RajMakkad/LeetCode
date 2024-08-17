#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        ll dp[n][m];
        ll left_dp[m], right_dp[m];
        for(int c = 0; c < m; c++)
            dp[0][c] = points[0][c];
        for(int r = 1; r < n; r++){
            left_dp[0] = dp[r - 1][0];
            for(int c = 1; c < m; c++)
                left_dp[c] = max(left_dp[c - 1], dp[r - 1][c] + c);
            right_dp[m - 1] = dp[r - 1][m - 1] - m + 1;
            for(int c = m - 2; c >= 0; c--)
                right_dp[c] = max(right_dp[c + 1], dp[r - 1][c] - c);
            for(int c = 0; c < m; c++)
                dp[r][c] = max(left_dp[c] - c, right_dp[c] + c) + points[r][c];
        }
        ll res = 0;
        for(auto &i: dp[n - 1])
            res = max(res, i);
        return res;
    }
};