class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int,int>> q;
        if(grid[0][0] || grid[n - 1][n - 1]) return -1;
        
        q.push({0,0});
        grid[0][0] = 1;
        
        int dx[] = {-1,1,0,0,-1,-1,1,1};
        int dy[] = {0,0,1,-1,-1,1,1,-1};
        
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0;i<8;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                
                if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < n and !grid[x1][y1]){
                    grid[x1][y1] = grid[x][y] + 1;
                    q.push({x1,y1});
                }
            }
        }
        
        return grid[n - 1][n - 1] ? grid[n - 1][n - 1] : -1;
    }
};