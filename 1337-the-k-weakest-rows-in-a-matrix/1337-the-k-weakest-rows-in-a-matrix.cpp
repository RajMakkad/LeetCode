class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pair<int,int>> od;

        for(int i = 0;i<n;i++){
            int x = 0;
            for(int j = 0;j<m;j++){
                x += (mat[i][j]);
            }
            od.push_back({x,i});
        }

        sort(od.begin(),od.end());
        vector<int> ans;
        for(int i = 0;i<k;i++) ans.push_back(od[i].second);

        return ans;
    }
};