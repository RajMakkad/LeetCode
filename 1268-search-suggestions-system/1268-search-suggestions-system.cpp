class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        int n = p.size(), m = s.size();
        sort(p.begin(), p.end());

        vector<int> a[m];

        for(int i = 0;i < n; i++){
            for(int j = 0;j < min(p[i].size(), s.length()); j++){
                if(s[j] == p[i][j]){
                    if((int)a[j].size() < 3) a[j].push_back(i);
                }
                else break;
            }
        }

        vector<vector<string>> ans(m);
        for(int i = 0;i < m;i++){
            vector<string> x;
            for(int j:a[i]){
                x.push_back(p[j]);
            }

            ans[i] = x;
        }

        return ans;
    }
};
