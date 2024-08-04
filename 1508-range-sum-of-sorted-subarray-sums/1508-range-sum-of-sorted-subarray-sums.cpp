#define pi pair<int, int>
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<pi, vector<pi>, greater<pi>> q;
        for(int i = 0; i < n; i++)
            q.push({nums[i], i});
        const int mod = 1e9 + 7;
        int ans = 0;
        for(int i = 0; i < right; i++){
            pi t = q.top();
            q.pop();
            if(i >= left - 1) 
                ans = (ans + t.first) % mod;
            if(t.second < n - 1)
                q.push({(t.first + nums[++t.second]) % mod, t.second});
        }
        return ans;
    }
};