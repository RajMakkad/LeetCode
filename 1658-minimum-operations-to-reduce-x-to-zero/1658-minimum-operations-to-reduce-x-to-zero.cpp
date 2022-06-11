class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int ans = n + 1;
        int sum = 0;
        int s = 0;

        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        
        if(x > sum) return -1;

        x = sum - x;
        sum = 0;

        for(int i = 0;i<n;i++){
            sum += nums[i];

            while(sum > x) sum = sum - nums[s++];
            if(sum == x) ans = min(ans, s + n - i - 1);
        }

        return ans == n + 1 ? -1: ans;
    }
};