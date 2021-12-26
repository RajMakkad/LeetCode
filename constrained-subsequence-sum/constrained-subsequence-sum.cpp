class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> q;
        
        int ans = -1e4;
        
        for(int i = 0;i<n;i++){
            while(q.size() and i - q.top().second > k) q.pop();
            if(q.size()) nums[i] += q.top().first;
            
            ans = max(ans,nums[i]);
            if(nums[i]>0) q.push({nums[i],i});
        }
        
        return ans;
    }
};