

class Solution {
    void minReach(vector<vector<int>> &grid, vector<vector<int>> &md) {
        int rows = md.size();
        int cols = md[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        queue<pair<int, int>> q;
        for(int r = 0;r < rows;r++) {
            for(int c = 0;c < cols;c++) {
                if(grid[r][c] == 1) {
                    q.push({r, c});
                    md[r][c] = 0;
                }
            }
        }
        
        while(!q.empty()){
            auto node = q.front();
            int r = node.first;
            int c = node.second;
            q.pop();
            
            for(int i = 0;i < 4;i++){
                int x = r + dx[i];
                int y = c + dy[i];
                if(x >= 0 and y >= 0 and x < rows and y < cols and md[x][y] > md[r][c] + 1){
                    md[x][y] = md[r][c] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    
    int maxSafeness(vector<vector<int>> &md){
        int rows = md.size();
        int cols = md[0].size();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int ans = 0;
        
        priority_queue<vector<int>> q;
        q.push({md[0][0], 0, 0});
        md[0][0] = -1;
        while(!q.empty()){
            vector<int> cell = q.top();
            if(cell[1] == rows - 1 and cell[2] == cols - 1){
                ans = cell[0];
                break;
            }
            
            q.pop();
            
            for(int i = 0;i < 4;i++){
                int x = cell[1] + dx[i];
                int y = cell[2] + dy[i];
                if(x >= 0 and y >= 0 and x < rows and y < cols and md[x][y] != -1){
                    q.push({min(cell[0], md[x][y]), x, y});
                    md[x][y] = -1;
                }
            }
        }
        return ans;
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> md(rows, vector<int>(cols, 1e9));
        minReach(grid, md);
        return maxSafeness(md);
    }
};