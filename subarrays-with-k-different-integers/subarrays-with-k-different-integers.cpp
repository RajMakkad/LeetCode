class Solution {
    int subWithNDistinct(vector<int>& nums, int k){
        int n = nums.size();
        int sub = 0;
        int s = 0;
        map<int,int> mp;
        
        for(int i = 0;i<n;i++){
            mp[nums[i]]++;
            
            while(mp.size() > k){
                mp[nums[s]]--;
                if(mp[nums[s]] == 0) mp.erase(nums[s]);
                s++;
            }
            
            sub += (i - s + 1);
        }
        
        return sub;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = subWithNDistinct(nums,k) - subWithNDistinct(nums,k - 1); 
        return ans;
    }
};