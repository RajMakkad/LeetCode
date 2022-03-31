class Solution{
    bool ispossible(int mid,int m,vector<int> &nums){
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] > mid) return false;
            sum += nums[i];
            if(sum > mid){
                m--;
                sum = nums[i];
            }
        }
        
        if(sum > 0) m--;
        return m >= 0;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int s = 0;
        int e = 1e9;
        int mid = s + (e - s)/2;

        while(e >= s){
            mid = s + (e - s)/2;
            if(ispossible(mid,m,nums)) e = mid - 1;
            else s = mid + 1;
        }

        return s;
    }
};
