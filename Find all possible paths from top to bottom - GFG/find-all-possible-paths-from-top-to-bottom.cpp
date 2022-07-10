// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    void solve(int x, int y, int n, int m, vector<int> &path, vector<vector<int>> &allPaths, vector<vector<int>> &grid){
        path.push_back(grid[x][y]);
        if(x == n - 1 and y == m - 1){
            allPaths.push_back(path);
        }
        else {
            if(x + 1 < n) solve(x + 1, y, n, m, path, allPaths, grid);
            if(y + 1 < m) solve(x, y + 1, n, m, path, allPaths, grid);
        }
        
        path.pop_back();
    }
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid){
        vector<vector<int>> allPaths;
        vector<int> path;
        
        solve(0, 0, n, m, path, allPaths, grid);
        return allPaths;
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends