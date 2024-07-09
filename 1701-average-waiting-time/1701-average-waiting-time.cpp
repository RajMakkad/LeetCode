class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0.0;
        double n = customers.size();
        int chef = 0;
        for(auto &i: customers){
            ans += max(chef - i[0], 0) + i[1];
            chef = max(i[0] + i[1], chef + i[1]);
        }
        return ans / n; 
    }
};