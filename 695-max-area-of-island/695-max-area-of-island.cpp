class Solution {

    void getArea(int x,int y,vector<vector<int>>& grid,int &cnt){
        grid[x][y] = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(x1>=0 and y1>=0 and x1<n and y1<m and grid[x1][y1]){
                getArea(x1,y1,grid,cnt);
            }
        }
        cnt++;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]){
                    int cnt = 0;
                    getArea(i,j,grid,cnt);
                    ans = max(ans,cnt);
                }
            }
        }

        return ans;
    }
};