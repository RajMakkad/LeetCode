// Deque
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
// o(n)



// Max priority queue.
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
// o(nlogn)
