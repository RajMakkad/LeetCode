class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> ans;
        for(int i = 0;i < n;i++){
            if(i > 0 and nums[i] == nums[i - 1]) continue;
            
            for(int j = i + 1;j < n;j++){
                if(j > i + 1 and nums[j] == nums[j - 1]) continue;
                
                int s = j + 1;
                int e = n - 1;
                long long t = target - nums[i] * 1LL - nums[j] * 1LL;
                
                while(e > s){
                    int sum = nums[s] + nums[e];
                    if(sum > t) e--;
                    else if(t > sum) s++;
                    else {
                        ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                        s++;
                        
                        while(s < e and nums[s] == nums[s - 1]) s++;
                    }
                }
            }
        }
        
        return ans;
    }
};