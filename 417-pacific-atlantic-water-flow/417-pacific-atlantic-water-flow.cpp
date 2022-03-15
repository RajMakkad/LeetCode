class Solution {
    void reachcells(int x,int y,vector<vector<int>> &h,vector<vector<int>> &visited){
        int n = h.size();
        int m = h[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        visited[x][y] = 1;

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and h[x1][y1] >= h[x][y] and !visited[x1][y1]){
                reachcells(x1,y1,h,visited);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<vector<int>> pacific(n,vector<int>(m,0));

        for(int i = 0;i<n;i++){
            if(atlantic[i][m - 1] == 0) reachcells(i,m - 1,h,atlantic);
            if(pacific[i][0] == 0) reachcells(i,0,h,pacific);
        }

        for(int i = 0;i<m;i++){
            if(atlantic[n - 1][i] == 0) reachcells(n - 1,i,h,atlantic);
            if(pacific[0][i] == 0) reachcells(0,i,h,pacific);
        }

        vector<vector<int>> ans;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(atlantic[r][c] and pacific[r][c]){
                    ans.push_back({r,c});
                }
            }
        }

        return ans;
    }
};