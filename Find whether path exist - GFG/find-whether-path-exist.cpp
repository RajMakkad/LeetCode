// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class Solution{
    bool dfs(int x,int y,vector<vector<int>> &g){
        int n = g.size();
        int m = g[0].size();
        g[x][y] = 0;

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m){
                if(g[x1][y1] == 2) return true;
                else if(g[x1][y1] == 3 and dfs(x1,y1,g)) return true;
            }
        }

        return false;
    }
    public:
    bool is_Possible(vector<vector<int>>& g){
        int n = g.size();
        int m = g[0].size();

        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(g[r][c] == 1 and dfs(r,c,g)){
                    return true;
                }
            }
        }

        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends