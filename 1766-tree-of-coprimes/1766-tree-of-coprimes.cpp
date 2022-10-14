#define pi pair<int, int>
#define ff first
#define ss second


class Solution {
    void solve(int node, int r, vector<int> &nums, vector<int> g[], vector<pi> v[], vector<int> &ans){
        pi sub = {1e9, -1};
        int size = 0;
        
        for(int i = 1;i <= 50;i++){
            size = v[i].size();
            if(size == 0) continue;
            
            int ob1 = v[i][size - 1].ff;
            int ob2 = v[i][size - 1].ss;
            
            if(__gcd(i, nums[node]) == 1){
                if(sub.ff > r - ob1) sub = {r - ob1, ob2};
            }
        }
        
        ans[node] = sub.ss;
        v[nums[node]].push_back({r, node});
        
        for(auto i:g[node]){
            if(ans[i] == -2){
                solve(i, r + 1, nums, g, v, ans);
            }
        }
        
        v[nums[node]].pop_back();
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> g[n];
        vector<pi> v[50 + 1];
        
        for(auto i:edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        
        vector<int> ans(n, -2);
        solve(0, 0, nums, g, v, ans);
        
        return ans;
    }
};