class Solution {
public:
    int search(vector<int>& nums, int x) {
    
        int l = 0, h = nums.size() - 1;

        while(l <= h){
            int mid = l + (h - l) / 2;

            if(nums[mid] == x) 
                return mid;

            if(nums[l] <= nums[mid]) {
                if(nums[l] <= x && x <= nums[mid])
                    h = mid - 1;
                else
                    l = mid + 1;
            }
            else if(nums[mid] < nums[l]) {
                if(nums[mid] <= x && x <= nums[h])
                    l = mid + 1;
                else 
                    h = mid - 1;
            }
        }

        return -1;
    }
};