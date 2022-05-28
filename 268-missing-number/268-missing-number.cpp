class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n;
        for(int i = 0;i<n;i++){
            sum += i;
            sum -= nums[i];
        }
        
        return sum;
    }
};