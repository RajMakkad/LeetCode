class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        int vis[n][m];

        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                vis[i][j] = 0;
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and vis[x1][y1] == 0){
                    vis[x1][y1] = 1;
                    mat[x1][y1] = mat[x][y] + 1;
                    q.push({x1,y1});
                }
            }
        }
        return mat;
    }
};