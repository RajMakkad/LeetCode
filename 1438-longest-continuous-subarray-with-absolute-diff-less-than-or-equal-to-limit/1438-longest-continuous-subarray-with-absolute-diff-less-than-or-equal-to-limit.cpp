class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_, min_;
        int n = nums.size(), left = 0, ans = 0;
        for(int right = 0; right < n; right++){
            while((int)max_.size() > 0 and nums[max_.back()] <= nums[right])
                max_.pop_back();
            max_.push_back(right);
            while((int)min_.size() > 0 and nums[min_.back()] >= nums[right])
                min_.pop_back();
            min_.push_back(right);
            while(nums[max_.front()] - nums[min_.front()] > limit){
                if(left == max_.front())
                    max_.pop_front();
                if(left == min_.front())
                    min_.pop_front();
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};