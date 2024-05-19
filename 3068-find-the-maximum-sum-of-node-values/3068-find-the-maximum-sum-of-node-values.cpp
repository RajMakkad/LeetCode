#define ll long long

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll n = nums.size();
        vector<vector<ll>> arr(n, vector<ll>(3));
        int count = 0;
        for(int i = 0; i < n; i++) {
            ll ai = nums[i] ^ k;
            arr[i][0] = ai - nums[i];
            arr[i][1] = ai;
            arr[i][2] = nums[i];
            count += arr[i][0] > 0 ? 1 : 0;
        }
        
        sort(arr.begin(), arr.end(), [&](const vector<ll> a, const vector<ll> b) {
            return a[0] < b[0];  
        });
        
        if(count % 2) {
            if(count == n) {
                count--;
            } else {
                if(arr[n - count][0] + arr[n - count - 1][0] > 0)
                    count++;
                else
                    count--;
            }
        }
        
        ll ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            ans += count > 0 ? arr[i][1] : arr[i][2];
            count--;
        }
        return ans;
    }
};