#define ll long long int
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& a) {
        const int n = a.size(), mod = 1e9 + 7;
        sort(a.begin(), a.end());
        
        ll ans = 0, max_ = a[n - 1];
        vector<ll> freq(2 * max_ + 1, 0), v(max_ + 1, 0);
        
        for(int i = 0;i < n;i++){
            v[a[i]]++;
            freq[a[i]]++;
        }
        
        for(int i = 1;i <= 2 * max_;i++) freq[i] += freq[i - 1];
        
        for(int i = 0;i < n;i++){
            if(v[a[i]] == 0) continue;
            
            ll s = a[i], e = 2 * a[i] - 1, d = 1;
            
            while(e <= 2 * max_){
                ans = (ans + (freq[e] - freq[s - 1]) * d * v[a[i]]) % mod;
                d++;
                s += a[i];
                e += a[i];
            }
            
            v[a[i]] = 0;
        }
        
        return ans;
    }
};