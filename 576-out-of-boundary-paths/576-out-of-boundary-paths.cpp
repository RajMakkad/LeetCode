#define mod 1000000007
class Solution {
    int memoization(int x, int y, int move, int n, int m, vector<vector<vector<int>>> &dp){
        if(x < 0 || y < 0 || x >= n || y >= m) return 1;
        if(move == 0) return 0;
        
        if(dp[x][y][move] != -1) return dp[x][y][move];
        
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        int ans = 0;
        for(int i = 0;i < 4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            ans = (ans + memoization(x1, y1, move - 1, n, m, dp))%mod;
        }
        
        return dp[x][y][move] = ans;
    }
public:
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(maxMove + 1, -1)));
        return memoization(startRow, startColumn, maxMove, n, m, dp);
    }
};