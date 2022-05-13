class Solution {
    int dp[101][101][200];
    int memoization(int x,int y,int k,vector<vector<char>>& g){
        int n = g.size();
        int m = g[0].size();

        k += (g[x][y] == '(' ? 1 : -1);
        if(k < 0) return 0;

        if(x == n - 1 and y == m - 1){
            return k == 0;
        }

        if(dp[x][y][k] != -1) return dp[x][y][k];

        int optimal = 0;
        if(x + 1 < n) optimal = memoization(x + 1,y,k,g);
        if(y + 1 < m) optimal |= memoization(x,y + 1,k,g);

        return dp[x][y][k] = optimal;
    }
public:
    bool hasValidPath(vector<vector<char>>& g){
        int n = g.size();
        int m = g[0].size();

        memset(dp,-1,sizeof(dp));
        return memoization(0,0,0,g);
    }
};