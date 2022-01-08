class Solution {
    int dp[72][72][72];
    
    bool in_bound(int x,int y1,int y2,int n,int m){
        return x>=0 and x<n and y1>=0 and y1<m and y2>=0 and y2<m;
    }
        
    int pick(int x,int y1,int y2,vector<vector<int>> &g){
        int n = g.size();
        int m = g[0].size();
        
        if(n == x) return dp[x][y1][y2] = 0;
        if(dp[x][y1][y2] != -1) return dp[x][y1][y2];
        
        int sub = 0;
        for(int i = -1;i<=1;i++){
            for(int j = -1;j<=1;j++){ 
                if(in_bound(x + 1,y1 + i,y2 + j,n,m)){
                    sub = max(sub,pick(x + 1,y1 + i,y2 + j,g));
                }
            }
        }
        
        return dp[x][y1][y2] = sub + (y1 == y2 ? g[x][y1] : g[x][y1] + g[x][y2]);
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        
        return pick(0,0,m-1,grid);
    }
};