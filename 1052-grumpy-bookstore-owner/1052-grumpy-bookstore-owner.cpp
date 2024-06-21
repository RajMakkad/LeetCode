class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sub = 0, acc = 0, ans = 0;
        for(int i = 0; i < customers.size(); i++)
            sub += grumpy[i] ? 0 : customers[i];
        for(int i = 0; i < customers.size(); i++){
            acc += customers[i];
            sub -= grumpy[i] ? 0 : customers[i];
            if(i - minutes >= 0){
                sub += grumpy[i - minutes] ? 0 : customers[i - minutes];
                acc -= customers[i - minutes];
            }
                
            ans = max(ans, sub + acc);
        }
        return ans;
    }
};