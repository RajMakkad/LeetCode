class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_sum = -1e9;
        int min_sum = 1e9;
        int curr_sum = 0;
        int curr_circular_sum = 1e9;
        int total_sum = 0;
        
        for(auto i:nums){
            if(curr_sum > 0) curr_sum += i;
            else curr_sum = i;
            
            if(curr_circular_sum >= 0) curr_circular_sum = i;
            else curr_circular_sum += i;
            
            max_sum = max(max_sum,curr_sum);
            min_sum = min(min_sum,curr_circular_sum);
            total_sum += i;
        }
        
        if(total_sum == min_sum) return max_sum;
        return max(max_sum,total_sum - min_sum);
    }
};