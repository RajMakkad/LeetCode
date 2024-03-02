class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int s = 0;
        int e = n - 1;
        int idx = n - 1;
        for(int i = 0;i < n;i++)
            nums[i] *= nums[i];
        while(e >= s){
            if(nums[e] >= nums[s])
                ans[idx--] = nums[e--];
            else
                ans[idx--] = nums[s++];
        }
        
        return ans;
    }
};