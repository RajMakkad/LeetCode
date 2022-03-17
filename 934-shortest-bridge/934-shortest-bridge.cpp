class Solution {
    queue<pair<int,int>> q;
    int ans = 1e9;

    bool is_valid(int x,int y,int n,int m){
        return x >= 0 and y >= 0 and x < n and y < m;
    }
    void eraseOneIsland(int x,int y,vector<vector<int>> &g,vector<vector<int>> &dist){
        int n = g.size();
        int m = g[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        dist[x][y] = g[x][y] = 0;
        q.push({x,y});

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(is_valid(x1,y1,n,m) and g[x1][y1] == 1){
                eraseOneIsland(x1,y1,g,dist);
            }
        }
    }

    void reachSecondIsland(vector<vector<int>> &g,vector<vector<int>> &dist){
        int n = g.size();
        int m = g[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if(is_valid(x1,y1,n,m) and dist[x1][y1] > dist[x][y] + 1){
                    q.push({x1,y1});
                    dist[x1][y1] = dist[x][y] + 1;
                    if(g[x1][y1] == 1) ans = min(ans,dist[x1][y1] - 1);
                }
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        bool pass = false;

        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(g[r][c] == 1){
                    eraseOneIsland(r,c,g,dist);
                    pass = true;
                    break;
                }
            }
            if(pass) break;
        }
        

        reachSecondIsland(g,dist);
        return ans;
    }
};