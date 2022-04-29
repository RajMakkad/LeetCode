#define mod 1000000007
class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n,0);
        p[0] = nums[0];
        for(int i = 1;i<n;i++){
            p[i] = p[i - 1] + nums[i];
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            auto u1 = lower_bound(p.begin() + i + 1,p.end() - 1,2*p[i]) - p.begin();

            auto u2 = upper_bound(p.begin(),p.end() - 1,(p[n - 1] + p[i])/2) - p.begin() - 1;
            
            if(u2 >= u1) ans = (ans + (u2 - u1 + 1)%mod)%mod;
        }

        return ans;
    }
};