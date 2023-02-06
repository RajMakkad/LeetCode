class Solution {
    const int mod = 1000 + 7;
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i = 0;i < n;i++){
            nums[i] = nums[i] + nums[n + i] * mod;
        }
        
        int idx = n - 1;
        for(int i = 2 * n - 1; i >= 0;i -= 2){
            nums[i] = nums[idx] / mod;
            nums[i - 1] = nums[idx] % mod;
            
            idx--;
        }
        
        return nums;
    }
};