class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dpl(n + 2,vector<int>(m + 2,0)), dpr(n + 2,vector<int>(m + 2,0));

        for(int x = 1;x<=n;x++){
            for(int y = 1;y<=m;y++){
                if(s[x - 1] == t[y - 1]) 
                    dpl[x][y] = dpl[x - 1][y - 1] + 1;
            }
        }

        for(int x = n;x >=1;x--){
            for(int y = m;y >= 1;y--){
                if(s[x - 1] == t[y - 1]) 
                    dpr[x][y] = dpr[x + 1][y + 1] + 1;
            }
        }

        int ans = 0;
        for(int x = 1;x <= n;x++){
            for(int y = 1;y <= m;y++){
                if(s[x - 1] != t[y - 1]){
                    ans += (dpl[x - 1][y - 1] + 1) * (dpr[x + 1][y + 1] + 1);
                }
            }
        }

        return ans;
    }
};