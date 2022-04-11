class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int n = g.size();
        int m = g[0].size();
        vector<int> a;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                a.push_back(g[r][c]);
            }
        }

        k %= (n*m);

        reverse(a.begin(),a.end());
        reverse(a.begin(),a.begin() + k);
        reverse(a.begin() + k,a.end());

        int idx = 0;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                g[r][c] = a[idx++];
            }
        }

        return g;
    }
};