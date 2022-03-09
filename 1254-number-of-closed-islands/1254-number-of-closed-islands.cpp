class Solution{
    void space(int x,int y,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int p = grid[x][y];
        
        grid[x][y] ^= 1;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        
        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            if(x1 >= 0 and x1 < n and y1 >= 0 and y1 < m and grid[x1][y1] == p){
                space(x1,y1,grid);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = 0;i<n;i++){
            if(grid[i][0] == 0) space(i,0,grid);
            if(grid[i][m - 1] == 0) space(i,m - 1,grid);
        }
        
        for(int i = 0;i<m;i++){
            if(grid[0][i] == 0) space(0,i,grid);
            if(grid[n - 1][i] == 0) space(n - 1,i,grid); 
        }
        
        int ans = 0;
        
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(grid[r][c] == 0){
                    ans++;
                    space(r,c,grid);
                }
            }
        }
        
        return ans;
    }
};