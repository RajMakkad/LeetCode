class Solution {
public:
    int countServers(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<int> a(n,0), b(m,0);

        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(g[r][c] == 1) a[r]++, b[c]++;
            }
        }

        int ans = 0;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(g[r][c] == 1 and (a[r] > 1 || b[c] > 1)) ans++;
            }
        }

        return ans;
    }
};