class Solution {
    int helper(vector<int> &nums, int &m){
        int count = 0;
        int n = nums.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < n and (nums[j] - nums[i]) <= m)
                j++;
            count += (j - i - 1);
        }
        return count;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0, e = nums[n - 1] - nums[0];
        int m = s + (e - s)/2;
        
        while(e >= s){
            m = s + (e - s)/2;
            if(helper(nums, m) >= k)
                e = m - 1;
            else
                s = m + 1;
        }
        return s;
    }
};