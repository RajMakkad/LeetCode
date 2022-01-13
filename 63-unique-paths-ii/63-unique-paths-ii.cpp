class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();

		int dp[n][m];
		memset(dp,0,sizeof(dp));

		if(!obstacleGrid[0][0]) dp[0][0] = 1;

		for(int r = 0;r<n;r++){
			for(int c = 0;c<m;c++){
				if(obstacleGrid[r][c]) continue;
				if(r > 0) dp[r][c] += dp[r - 1][c];
				if(c > 0) dp[r][c] += dp[r][c - 1];
			}
		}

		return dp[n - 1][m - 1];
    }
};