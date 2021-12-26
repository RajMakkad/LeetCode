class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        
        int ans = nums[0];
        
        for(int i = 0;i<n;i++){
            if(q.size()) nums[i] += nums[q.front()];
            ans = max(ans,nums[i]);
            
            while(q.size() and nums[i] > nums[q.back()]) q.pop_back();
            if(nums[i]>0) q.push_back(i);
            
            if(q.size() and q.front() == i - k) q.pop_front();
        }
        
        return ans;
    }
};