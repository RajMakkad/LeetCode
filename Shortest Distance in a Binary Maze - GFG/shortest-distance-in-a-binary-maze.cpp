//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define pi pair<int, int>
#define ff first
#define ss second

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s, pair<int, int> e) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        
        queue<pi> q;
        q.push({s.ff, s.ss});
        grid[s.ff][s.ss] = dist[s.ff][s.ss] = 0;
        
        while(!q.empty()){
            pi p = q.front();
            q.pop();
            
            for(int i = 0;i < 4;i++){
                int x = p.ff + dx[i];
                int y = p.ss + dy[i];
                
                if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1){
                    dist[x][y] = dist[p.ff][p.ss] + 1;
                    grid[x][y] = 0;
                    q.push({x, y});
                }
            }
        }
        
        int ans = dist[e.ff][e.ss];
        return ans == 1e9 ? -1: ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends