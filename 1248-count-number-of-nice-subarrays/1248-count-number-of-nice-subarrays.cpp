class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> odd;
        for(int i = 0; i < n; i++)
            if(nums[i] % 2)
                odd.push_back(i);
        int ans = 0, count = 0;
        for(int i = k - 1; i < odd.size(); i++){
            int l = 1, r = 1;
            if(i - k + 1 == 0)
                l += (odd[i - k + 1]);
            else if(i - k + 1 > 0)
                l += (odd[i - k + 1] - odd[i - k] - 1);
            if(i == odd.size() - 1)
                r += n - odd[i] - 1;
            else 
                r += (odd[i + 1] - odd[i] - 1);
            ans += l * r;
        }
        return ans;
    }
};