// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

int ans = -1;
class Solution {
    bool isValid(int x, int y, int n, int m){
        return x >= 0 and y >= 0 and x < n and y < m;
    }

    void dfs(int x, int y, int xd, int yd, int cnt, vector<vector<int>> &mat){
        if(x == xd and y == yd){
            ans = max(ans, cnt);
            return ;
        }
        
        mat[x][y] = 0;
        int n = mat.size();
        int m = mat[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(isValid(x1, y1, n, m) and mat[x1][y1] == 1){
                dfs(x1, y1, xd, yd, cnt + 1, mat);
            }
        }
        
        mat[x][y] = 1;
    }
public:
    int longestPath(vector<vector<int>> mat, int xs, int ys, int xd, int yd){
        int n = mat.size();
        int m = mat[0].size();

        ans = -1;
        if(mat[xs][ys] != 0) dfs(xs, ys, xd, yd, 0, mat);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends