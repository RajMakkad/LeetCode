class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for(int c = 0;c < m;c++){
            int setBit = 0;
            for(int r = 0;r < n;r++){
                if(grid[r][c] == grid[r][0])
                    setBit++;
            }
            ans = ans + (max(setBit, n - setBit) << (m - c - 1));
        }
        return ans;
    }
};