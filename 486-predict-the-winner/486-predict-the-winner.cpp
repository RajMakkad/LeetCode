class Solution {
    int solve(int s, int e, int n, vector<int> &nums){
        if(s == e) return nums[s];
        if(s > e) return 0;
        
        int ans1 = nums[s] + min(solve(s + 2, e, n, nums), solve(s + 1, e - 1, n, nums));
        int ans2 = nums[e] + min(solve(s + 1, e - 1, n, nums), solve(s, e - 2, n, nums));
        
        return max(ans1, ans2);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        int s = 0, e = n - 1;
        
        
        for(int i = 0;i < n;i++) sum += nums[i];
        
        int p1 = solve(s, e, n, nums);
        sum = sum - p1;
        
        return p1 >= sum ? true : false; 
    }
};