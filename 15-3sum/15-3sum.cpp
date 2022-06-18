class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(i > 0 and nums[i] == nums[i - 1]) continue;
            
            int t = -nums[i];
            int s = i + 1;
            int e = n - 1;
            while(e > s){
                if(nums[s] + nums[e] > t) e--;
                else if(nums[s] + nums[e] < t) s++;
                else {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    while(s < n and nums[s] == nums[s - 1]) s++;
                }
            }
        }
        
        return ans;
    }
};