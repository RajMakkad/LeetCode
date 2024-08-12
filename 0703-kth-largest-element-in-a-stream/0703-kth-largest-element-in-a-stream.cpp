class KthLargest {
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto &i: nums)
            q.push(i);
        while(q.size() > k)
            q.pop();
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > K)
            q.pop();
        return q.top();
    }
};