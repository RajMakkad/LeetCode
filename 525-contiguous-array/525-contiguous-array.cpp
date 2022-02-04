class Solution{
public:
    int findMaxLength(vector<int>& nums){
        unordered_map<int,int> cnt;
        cnt[0] = -1;
        int n = nums.size();
        int ans = 0;
        int sum = 0;

        for(int i = 0;i<n;i++){
            sum += nums[i] ? 1 : -1;
            if(cnt.count(sum)) ans = max(ans,i - cnt[sum]);
            else cnt[sum] = i;
        }

        return ans;
    }
};