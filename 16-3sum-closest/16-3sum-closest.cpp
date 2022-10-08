#define ff first
#define ss second

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n = nums.size();
        pair<int, int> ans = {1e9, 0};
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0;i < n;i++){
            int need = t - nums[i];
            int x = i + 1;
            int y = n - 1;
            
            while(y > x){
                int sum = nums[x] + nums[y];
                int d = abs(need - sum);
                
                if(ans.ff > d) ans = {d, nums[i] + sum};
                if(sum > need) y--;
                else x++;
            }
        }
        
        return ans.second;
    }
};