class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int lcount = 0; // count of 0's;
        int lpos = -1; // position of last 0 from left;
        int rcount = 0;
        int rpos = n; // position of last 0 from right;
        
        for(int i = 0;i<n;i++){
            if(nums[i] < 0) lcount++;
            if(nums[n - i - 1] < 0) rcount++;
            
            if(nums[i] == 0){
                lpos = i;
                lcount = 0;
            }
            
            if(nums[n - i - 1] == 0){
                rpos = n - i - 1;
                rcount = 0;
            }
            
            if(lcount%2 == 0) ans = max(ans,i - lpos);
            if(rcount%2 == 0) ans = max(ans,rpos - (n - i - 1));
        }
        
        return ans;
    }
};