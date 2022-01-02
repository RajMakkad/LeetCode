class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int start = k;
        int end = k;
        int ans = nums[k];
        int cmin = nums[k];
        
        while(start>0 || end + 1 < n){
            if(start > 0 and end + 1 < n){
                if(nums[start - 1] > nums[end + 1]) cmin = min(cmin,nums[--start]);
                else cmin = min(cmin,nums[++end]);
            }
            else if(start > 0) cmin = min(cmin,nums[--start]);
            else cmin = min(cmin,nums[++end]);
            
            ans = max(ans,cmin*(end - start + 1));
        }
        
        return ans;
    }
};