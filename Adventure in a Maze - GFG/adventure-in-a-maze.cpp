// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
#define pi pair<int,int>
#define mod 1000000007
vector<int> FindWays(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<pi>> dp(n,vector<pi>(m,{0,0}));
    dp[0][0] = {1,mat[0][0]};

    for(int r = 0;r<n;r++){
        for(int c = 0;c<m;c++){
            if(dp[r][c].first == 0) continue;
            
            if((mat[r][c] == 1 || mat[r][c] == 3) and c + 1 < m){
                dp[r][c + 1].first = (dp[r][c + 1].first + dp[r][c].first%mod)%mod;
                dp[r][c + 1].second = max(dp[r][c + 1].second,dp[r][c].second + mat[r][c + 1]);
            }

            if((mat[r][c] == 2 || mat[r][c] == 3) and r + 1 < n){
                dp[r + 1][c].first = (dp[r + 1][c].first + dp[r][c].first%mod)%mod;
                dp[r + 1][c].second = max(dp[r + 1][c].second,dp[r][c].second + mat[r + 1][c]);
            }
        }
    }
    
    return {dp[n - 1][m - 1].first,dp[n - 1][m - 1].second};
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		vector<int> ans = obj.FindWays(matrix);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends