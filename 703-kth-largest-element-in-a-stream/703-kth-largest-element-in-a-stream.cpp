class KthLargest {
    priority_queue<int,vector<int>,greater<int>> q;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i = 0;i<nums.size();i++) q.push(nums[i]);
    }
    
    int add(int val) {
        q.push(val);
        while(q.size() > K) q.pop();
        return q.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */