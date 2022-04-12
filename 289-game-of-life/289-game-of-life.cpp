class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        int n = b.size();
        int m = b[0].size();
        int dx[] = {-1,0,1,0,-1,-1,1,1};
        int dy[] = {0,-1,0,1,-1,1,1,-1};

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int cnt = 0;
                for(int k = 0;k<8;k++){
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if(x >= 0 and x < n and y >= 0 and y < m and b[x][y] > 0) cnt++;
                }

                if(b[i][j]){
                    if(cnt < 2 || cnt > 3) b[i][j] = 3;
                    else b[i][j] = 4;
                }
                else{
                    if(cnt == 3) b[i][j] = -1;
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(b[i][j] == 4) b[i][j] = 1;
                if(b[i][j] == 3) b[i][j] = 0;
                else if(b[i][j] == -1) b[i][j] = 1;
            }
        }

    }
};