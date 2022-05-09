class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0)), ans;

        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                bool pass = true;
                if(land[r][c] == 1){
                    int x = r;
                    int y = c;
                    while(x < n and land[x][y] == 1){
                        if(vis[x][y] == 1){
                            pass = false;
                        }
                        x++;
                    }
                    x--;
                    while(y < m and land[x][y] == 1){
                        if(vis[x][y] == 1){
                            pass = false;
                        }
                        y++;
                    }
                    
                    y--;

                    if(pass){
                        ans.push_back({r,c,x,y});
                        vis[x][y] = 1;
                    }
                }
            }
        }

        return ans;
    }
};