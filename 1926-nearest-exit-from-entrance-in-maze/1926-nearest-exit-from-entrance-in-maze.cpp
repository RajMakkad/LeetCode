class Solution {
    bool is_valid(int x,int y,int n,int m){
        return x >= 0 and y >= 0 and x < n and y < m;
    }
    void exit(int r,int c,vector<vector<char>> &maze,vector<vector<int>> &dist){
        int n = maze.size();
        int m = maze[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        queue<pair<int,int>> q;

        q.push({r,c});
        maze[r][c] = '+';

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if(is_valid(x1,y1,n,m) and maze[x1][y1] == '.' and dist[x1][y1] > dist[x][y] + 1){
                    q.push({x1,y1});
                    maze[x1][y1] = '+';
                    dist[x1][y1] = dist[x][y] + 1;
                }
            }
        }
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e){
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        dist[e[0]][e[1]] = 0;
        exit(e[0],e[1],maze,dist);

        int ans = 1e9;
        dist[e[0]][e[1]] = 1e9;

        for(int r = 0;r<n;r++){
            ans = min({ans,dist[r][0],dist[r][m - 1]});
        }

        for(int c = 0;c<m;c++){
            ans = min({ans,dist[0][c],dist[n - 1][c]});
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};
