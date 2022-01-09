class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& g, int sh, int sw) {
        int n = g.size();
        int m = g[0].size();
        int z = 4;

        int gr[n][m][z];


        for(int i = 0;i<n;i++){
            int left = 0;
            for(int j = 0;j<m;j++){
                if(g[i][j] == 1) left = 0;
                else{
                    gr[i][j][0] = left;
                    left++;
                }

            }
        }

        for(int i = 0;i<n;i++){
            int right = 0;
            for(int j = m - 1;j>=0;j--){
                if(g[i][j] == 1) right = 0;
                else{
                    gr[i][j][1] = right;
                    right++;
                }
            }
        }

        for(int i = 0;i<m;i++){
            int up = 0;
            for(int j = 0;j<n;j++){
                if(g[j][i] == 1) up = 0;
                else{
                    gr[j][i][2] = up;
                    up++;
                }
            }
        }

        for(int i = 0;i<m;i++){
            int down = 0;
            for(int j = n - 1;j>=0;j--){
                if(g[j][i] == 1) down = 0;
                else{
                    gr[j][i][3] = down;
                    down++;
                }
            }
        }

        for(int i = 0;i<n;i++){
            int mup = 1e9;
            int mdown = 1e9;
            for(int j = 0;j<m;j++){
                if(g[i][j] == 0){
                    mup = min(mup,gr[i][j][2]);
                    gr[i][j][2] = mup;
                    mdown = min(mdown,gr[i][j][3]);
                    gr[i][j][3] = mdown;
                }
                else mup = mdown = 1e9;
            }
        }

        for(int i = 0;i<n;i++){
            int mup = 1e9;
            int mdown = 1e9;
            for(int j = 0;j<m;j++){
                if(g[i][j] == 0){
                    mup = min(mup,gr[i][j][2]);
                    gr[i][j][2] = mup;
                    mdown = min(mdown,gr[i][j][3]);
                    gr[i][j][3] = mdown;
                }
                else mup = mdown = 1e9;
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(g[i][j] == 0){
                    int h = gr[i][j][2] + gr[i][j][3] + 1;
                    int w = gr[i][j][0] + gr[i][j][1] + 1;

                    if(sh>h || sw > w) return false;
                }
            }
        }

        return true;
    }
};