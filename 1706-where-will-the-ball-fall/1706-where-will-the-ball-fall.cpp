class Solution {
    int pass(int c,int n,int m,vector<vector<int>>& g){
        int r = 0;
        while(r < n){
            if(g[r][c] == 1){
                if(c + 1 < m and g[r][c + 1] != -1) r++, c++;
                else return -1;
            }
            else{
                if(c > 0 and g[r][c - 1] != 1) r++, c--;
                else return -1;
            }
        }

        return c;
    }
public:
    vector<int> findBall(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        vector<int> ans(m);
        for(int c = 0;c<m;c++){
            ans[c] = pass(c,n,m,g);
        }

        return ans;
    }
};