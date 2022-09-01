#define ll long long int
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        ll n = beans.size();
        ll p = 0, s = 0, ans = 1e18;
        
        for(auto &i:beans){
            s += i;
        }
        
        for(ll i = 0;i < n;i++){
            ans = min(ans, p + (s - (n - i) * beans[i] * 1LL));
        }
        
        return ans;
    }
};