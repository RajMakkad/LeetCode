// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int dp[101][101];
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    int memoization(int x,int y,vector<vector<int>>& mat){
        if(dp[x][y] != -1) return dp[x][y];
    
        int n = mat.size(), m = mat[0].size();
        int path = 0;
    
        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
    
            if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and mat[x1][y1] > mat[x][y]){
                path = max(path,memoization(x1,y1,mat));
            }
        }
    
        return dp[x][y] = path + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& mat){
        int n = mat.size(), m = mat[0].size();
        memset(dp,-1,sizeof(dp));
    
        int ans = 0;
    
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                ans = max(ans,memoization(r,c,mat));
            }
        }
    
        return ans;
    }
};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends