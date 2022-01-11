class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int> row = {t[0][0]};
        
        for(int i = 1;i<n;i++){
            int m = t[i].size();
            vector<int> sub(m,1e9);
            
            for(int in = 0;in<row.size();in++){
                sub[in] = min(sub[in],t[i][in] + row[in]);
                sub[in + 1] = min(sub[in + 1],t[i][in + 1] + row[in]);
            }
            
            row = sub;
        }
        
        int ans = 1e9;
        
        for(int i = 0;i<n;i++) ans = min(ans,row[i]);
        return ans;
    }
};