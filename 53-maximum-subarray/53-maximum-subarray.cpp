class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = -1e5;

        for(auto &i:nums){
            if(sum > 0) sum += i;
            else sum = i;
            ans = max(ans,sum);
        }

        return ans;
    }
};