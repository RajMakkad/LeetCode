static bool sorter(const vector<int> &a,const vector<int> &b){
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end(),sorter);
        vector<int> v, ans;

        for(int i = 0;i<e.size();i++) v.push_back(e[i][1]);

        for(int i = 0;i<v.size();i++){
            if(ans.empty() || v[i] > ans.back()) ans.push_back(v[i]);
            else{
                auto u = lower_bound(ans.begin(),ans.end(),v[i]) - ans.begin();
                ans[u] = v[i]; 
            }
        }

        return (int) ans.size();
    }
};