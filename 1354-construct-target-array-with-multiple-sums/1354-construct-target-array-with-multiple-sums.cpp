class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        long long sum = 0;
        priority_queue<int> q;
        
        for(int i:target){
            sum += i;
            q.push(i);
        }
        
        while(q.top() != 1){
            int t = q.top();
            q.pop();
            
            sum = sum - t;
            if(sum >= t) return false;
            
            if(sum == 1) {
                if(n == 2) return true;
                else return false;
            }
            if(sum == 0 || t % sum == 0) return false;
            
            int e = t % sum;
            sum += e;
            
            q.push(e);
        }
        
        return true;
    }
};