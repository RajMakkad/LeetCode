class Solution {
    void dfs(int x,int y,vector<vector<char>>& g){
        g[x][y] = '0';
        int n = g.size();
        int m = g[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and g[x1][y1] == '1'){
                dfs(x1,y1,g);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }

        return ans;
    }
};
