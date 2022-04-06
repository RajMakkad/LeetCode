#define mod 1000000007
class Solution {
public:
    int threeSumMulti(vector<int>& a, int target){
        int n = a.size();
        int ans = 0;
        
        for(int it = 0;it<n;it++){
            if(a[it] > target) continue;
            target -= a[it];

            vector<int> mp(301,0);
            for(int i = it + 1;i<n;i++){
                if(a[i] > target) continue;
                ans = (ans + mp[target - a[i]]%mod)%mod;
                mp[a[i]]++;
            }
            
            target += a[it];
        }

        return ans;
    }
};