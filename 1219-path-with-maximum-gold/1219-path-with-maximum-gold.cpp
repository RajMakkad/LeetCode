class Solution {
    bool conditions(int x, int y, int n, int m){
        return x < n and y < m and x >= 0 and y >= 0;
    }
    int maximumGold(int x, int y, int &n, int &m, vector<vector<int>>& grid){
        int currGold = grid[x][y];
        int gold = 0;
        grid[x][y] = 0;
        
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};
        
        for(int d = 0;d < 4;d++){
            int newx = x + dx[d];
            int newy = y + dy[d];
            if(conditions(newx, newy, n, m) and grid[newx][newy] > 0){
                gold = max(gold, maximumGold(newx, newy, n, m, grid));
            }
        }
        gold += currGold;
        grid[x][y] = currGold;
        return gold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int gold = 0;
        for(int r = 0;r < n;r++){
            for(int c = 0;c < m;c++){
                if(grid[r][c] > 0) {
                    gold = max(gold, maximumGold(r, c, n, m, grid));
                }
            }
        } 
        return gold;
    }
};