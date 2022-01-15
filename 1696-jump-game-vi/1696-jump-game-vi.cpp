class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        
        for(int i = 0;i<n;i++){
            if(q.size()) nums[i] += nums[q.front()];
            while(q.size() and nums[i] >= nums[q.back()]) q.pop_back();
            q.push_back(i);
            if(q.front() == i - k) q.pop_front();
        }
        
        return nums[n - 1];
    }
};