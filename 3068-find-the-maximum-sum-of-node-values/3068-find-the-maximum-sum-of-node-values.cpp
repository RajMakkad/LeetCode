class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, count = 0, sacrifice = INT_MAX;
        for(long long num: nums){
            sum += max((num ^ k), num);
            count += (num ^ k) > num;
            sacrifice = min(sacrifice, abs((num ^ k) - num));
        }
        return count % 2 ? sum - sacrifice : sum;
    }
};