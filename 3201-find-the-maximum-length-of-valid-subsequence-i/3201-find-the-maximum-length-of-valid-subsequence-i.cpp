class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size(), odd = 0, ans = 0;
        for(auto &i: nums)
            odd += i % 2;
        ans = max(odd, n - odd);
        int flag = 0, count1 = 0, count2 = 0;
        for(auto &i: nums){
            if(flag % 2 == i % 2){
                flag = !flag;
                count1++;
            }
        }
        flag = 1;
        for(auto &i: nums){
            if(flag % 2 == i % 2){
                flag = !flag;
                count2++;
            }
        }
        return max({ans, count1, count2});
    }
};