class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int sum = 0;
        int ans = n + 1;
        
        for(int e = 0;e<n;e++){
            sum += nums[e];
            while(sum >= target){
                ans = min(ans,e - s + 1);
                sum = sum - nums[s++];
            }
        }
        
        return ans < n + 1 ? ans : 0;
    }
};