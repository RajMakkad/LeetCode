class Solution {
    int dfs(int x, int y, vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0){
            return 0;
        }
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        grid[x][y] = 0;
        int ans = 1;
        
        for(int i = 0;i < 4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            ans += dfs(x1, y1, grid);
        }
        
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        for(int r = 0;r < n;r++){
            for(int c = 0;c < m;c++){
                if(grid[r][c] == 1){
                    ans = max(ans, dfs(r, c, grid));
                }
            }
        }
        
        return ans;
    }
};