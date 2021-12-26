class Solution {
    vector<int> res;
public:
    Solution(vector<int>& nums) {
        res = nums;
    }
    
    vector<int> reset() {
        return res;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = res;
        int n = res.size();
        
        for(int i = n - 1;i>=0;i--){
            int index = rand()%n;
            swap(shuffled[index],shuffled[i]);
            n--;
        }
        
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */