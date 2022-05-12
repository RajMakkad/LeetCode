class Solution {
public:
    int countNegatives(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        int x = 0, y = m - 1;

        int ans = 0;

        while(x < n and y >= 0){
            if(g[x][y] < 0) y--;
            else{
                ans += (m - y - 1);
                x++;
            }
        }

        ans += (n - x)*m;
        return ans;
    }
};