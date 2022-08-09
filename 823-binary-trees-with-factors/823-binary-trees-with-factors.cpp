#define mod 1000000007
#define ll long long int
class Solution {
    unordered_map<ll, ll> vis, dp;
    
    ll solve(int node){
        if(vis.find(node) == vis.end()) return 0;
        if(dp.find(node) != dp.end()) return dp[node];
        
        ll ans = 1;
        for(int i = 2;i * i <= node;i++){
            if(node % i != 0) continue;
            ll cnt = 1;
            if(i * i != node) cnt = 2LL;
            ans = (ans + cnt * solve(i) * solve(node / i)) % mod;
        }
        
        return dp[node] = ans;
    }
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        ll n = a.size(), ans = 0;
        
        for(int i = 0;i < n;i++){
            vis[a[i]] = 1;
        }
        
        for(int i = 0;i < n;i++){
            ans = (ans + solve(a[i])) % mod;
        }
        
        return ans;
    }
};