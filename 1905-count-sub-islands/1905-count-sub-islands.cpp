class Solution {
    void space(int x,int y,vector<vector<int>>& g1, vector<vector<int>>& g2,bool &pass){
        int n = g1.size();
        int m = g1[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        if(g1[x][y] != 1) pass = false;
        g2[x][y] = 0;

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and g2[x1][y1] == 1){
                space(x1,y1,g1,g2,pass);
            }
        }
    }
public:
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2){
        int n = g1.size();
        int m = g1[0].size();

        int ans = 0;

        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(g2[r][c] == 1){
                    bool pass = true;
                    space(r,c,g1,g2,pass);
                    
                    if(pass) ans++;
                }
            }
        }

        return ans;
    }
};
