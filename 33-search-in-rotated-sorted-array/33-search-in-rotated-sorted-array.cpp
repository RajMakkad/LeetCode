class Solution {
public:
    int search(vector<int>& nums, int target){
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int m = s + (e - s)/2;

        while(e >= s){
            m = s + (e - s)/2;

            if(nums[m] == target) return m;
            else if(nums[m] > target){
                if(target >= nums[0]) e = m - 1;
                else{
                    if(nums[m] >= nums[0]) s = m + 1;
                    else e = m - 1;
                }
            }
            else if(target > nums[m]){
                if(target >= nums[0]){
                    if(nums[m] >= nums[0]) s = m + 1;
                    else e = m - 1;
                }
                else s = m + 1;
            }
        }

        return -1;
    }
};