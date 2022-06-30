class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long sum = 0, pre = 0, ans = 1e15 ,n = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }
        
        for(long long i = 0;i < n;i++){
            long long curr = (sum - pre - (n - i) * nums[i] * 1LL);
            curr += i * nums[i] - pre;
            
            ans = min(ans, curr);
            pre += nums[i];
        }
        
        return ans;
    }
};