class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> q;
        
        for(int i = 0;i < nums.size();i++){
            if(!q.empty()) nums[i] += nums[q.front()];
            
            while(!q.empty() and nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            
            if(i - k == q.front()) q.pop_front();
        }
        
        return nums.back();
    }
};