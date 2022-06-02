// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
    bool traverse(int x,int y,vector<vector<int>> &ans,vector<vector<int>> &mat){
        int n = mat.size(), m = mat[0].size();
        ans[x][y] = 1;

        if(x == n - 1 and y == m - 1) return true;

        for(int k = 1;k <= mat[x][y];k++){
            int x1 = x + k;
            int y1 = y + k;

            if(y1 < m and traverse(x,y1,ans,mat)) return true;
            if(x1 < n and traverse(x1,y,ans,mat)) return true;
        }

        ans[x][y] = 0;
        return false;
    }
public:
	vector<vector<int>> ShortestDistance(vector<vector<int>> &mat){
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));

        if(traverse(0,0,ans,mat) and ans[n - 1][m - 1] > 0) return ans;
        else return {{-1}};
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends