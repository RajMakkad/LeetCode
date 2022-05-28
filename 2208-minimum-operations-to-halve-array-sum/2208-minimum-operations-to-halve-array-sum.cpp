class Solution {
public:
    int halveArray(vector<int>& nums) {
        long double need = 0, sum = 0;
        priority_queue<double> q;
        
        for(int i:nums){
            need += i;
            q.push(i);
        }
        
        sum = need;
        need /= 2.0;
        int ans = 0;
        
        while(sum > need){
            double x = q.top();
            q.pop();
            sum -= x/2;
            
            q.push(x/2);
            ans++;
        }
        
        return ans;
    }
};