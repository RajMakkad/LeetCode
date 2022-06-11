class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        map<int,int> mp;
        mp[0] = 0;

        int n = nums.size();
        int sum = 0;
        for(int i = n - 1;i>=0;i--){
            sum += nums[i];
            mp[sum] = (n - i);
        }

        sum = 0;
        int ans = n + 1;
        if(mp.find(x) != mp.end()) ans = min(ans, mp[x]);


        for(int i = 0;i<n;i++){
            sum += nums[i];
            int need = x - sum;

            if(mp.find(need) != mp.end()){
                ans = min(ans, i + 1 + mp[need]);
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};