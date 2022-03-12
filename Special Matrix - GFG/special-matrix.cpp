// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

#define mod 1000000007
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>> blocked_cells){
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        dp[1][1] = 1;

        for(auto &i:blocked_cells){
            dp[i[0]][i[1]] = -1;
        }

        for(int r = 1;r<=n;r++){
            for(int c = 1;c<=m;c++){
                if(dp[r][c] == -1) continue;
                if(c > 1 and dp[r][c - 1] != -1) dp[r][c] = (dp[r][c] + dp[r][c - 1])%mod;
                if(r > 1 and dp[r - 1][c] != -1) dp[r][c] = (dp[r][c] + dp[r - 1][c])%mod;
            }
        }

        return dp[n][m] == -1 ? 0 : dp[n][m];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends