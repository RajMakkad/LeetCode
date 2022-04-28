class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& p) {
        int n = flowers.size(), m = p.size();
        vector<int> s, e, ans(m);

        for(auto i:flowers){
            s.push_back(i[0]);
            e.push_back(i[1]);
        }

        sort(s.begin(),s.end());
        sort(e.begin(),e.end());

        for(int i = 0;i<m;i++){
            int x = upper_bound(s.begin(),s.end(),p[i]) - s.begin();
            int y = lower_bound(e.begin(),e.end(),p[i]) - e.begin();
            ans[i] = n - (n - x) - y;
        }

        return ans;
    }
};