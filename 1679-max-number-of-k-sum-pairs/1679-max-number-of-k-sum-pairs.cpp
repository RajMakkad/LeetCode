class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size() - 1;
        int ans = 0;

        while(e > s){
            int sum = nums[s] + nums[e];
            if(sum > k) e--;
            else if(sum < k) s++;
            else{
                s++;
                e--;
                ans++;
            }
        }

        return ans;
    }
};