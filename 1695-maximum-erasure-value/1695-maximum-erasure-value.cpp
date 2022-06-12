class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int sum = 0;
        int ans = 0;
        
        vector<int> count(10001, 0);

        for(int i = 0;i<n;i++){
            sum += nums[i];
            count[nums[i]]++;

            while(count[nums[i]] > 1){
                sum = sum - nums[s];
                count[nums[s++]]--;
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};