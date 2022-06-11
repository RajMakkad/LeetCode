#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        ll s = 0;
        ll sum = 0;
        ll ans = 0;

        for(ll i = 0;i<n;i++){
            sum += nums[i];
            ll p = sum * (i - s + 1);

            while(p >= k){
                sum = sum - nums[s++];
                p = sum * (i - s + 1);
            }

            ans += (i - s + 1);
        }

        return ans;
    }
};