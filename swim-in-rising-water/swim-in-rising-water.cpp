class Solution {
    bool acceptable(int &depth,vector<vector<int>> grid){
        int n = grid.size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        
        queue<pair<int,int>> q;
        
        if(depth>=grid[0][0]){
            q.push({0,0});
            grid[0][0] = n*n;
        }
        
        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                
                if(x1>=0 and y1>=0 and x1<n and y1<n and depth>=grid[x1][y1]){
                    if(x1 == n - 1 and y1 == n - 1) return true;
                    q.push({x1,y1});
                    grid[x1][y1] = n*n;
                }
            }
            
        }
        
        return grid[n - 1][n - 1] == n*n ? true : false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int s = 0;
        int e = n*n - 1;
        int mid;
        
        while(e>=s){
            mid = s + (e - s)/2;
            if(acceptable(mid,grid)) e = mid - 1;
            else s = mid + 1;
        }
        
        return s;
    }
};