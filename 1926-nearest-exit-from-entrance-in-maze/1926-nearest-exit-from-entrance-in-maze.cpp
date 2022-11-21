#define pi pair<int, int>
#define ff first
#define ss second

class Solution {
    bool isBorder(int x, int y, int n, int m){
        return x + 1 == n || x == 0 || y == 0 || y + 1 == m;
    }
    bool isValid(int x, int y, int n, int m){
        return x < n and x >= 0 and y >= 0 and y < m;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int n = maze.size();
        int m = maze[0].size();
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        int ans = -1;
        
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[e[0]][e[1]] = 0;
        maze[e[0]][e[1]] = '+';
        
        queue<pi> q;
        q.push({e[0], e[1]});
        
        while(!q.empty()){
            int x = q.front().ff;
            int y = q.front().ss;
            
            q.pop();
            if(isBorder(x, y, n, m) and !(e[0] == x and e[1] == y) and ans == -1){
                ans = dp[x][y];
            }
            
            for(int i = 0;i < 4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if(isValid(x1, y1, n, m) and maze[x1][y1] == '.'){
                    dp[x1][y1] = dp[x][y] + 1;
                    maze[x1][y1] = '+';
                    
                    q.push({x1, y1});
                }
            }
        }
        
        return ans;
    }
};