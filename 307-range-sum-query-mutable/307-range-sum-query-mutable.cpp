class NumArray {
    int sg[200000], n = 0;
    vector<int> v;
    void build(int si, int s, int e, vector<int> &nums){
        if(s == e){
            sg[si] = nums[s];
            return ;
        }
        
        int m = s + (e - s)/2;
        build(2 * si + 1, s, m, nums);
        build(2 * si + 2, m + 1, e, nums);
        
        sg[si] = sg[2 * si + 1] + sg[2 * si + 2];
    }
    
    void pointUpdate(int si, int index, int s, int e, int val){
        if(index > e || index < s) return ;
        if(s == e){
            sg[si] = val;
            return ;
        }
        
        int m = s + (e - s)/2;
        
        pointUpdate(2 * si + 1, index, s, m, val);
        pointUpdate(2 * si + 2, index, m + 1, e, val);
        
        sg[si] = sg[2 * si + 1] + sg[2 * si + 2];
    }
    
    int getSum(int si, int l, int r, int s, int e){
        if(s >= l and r >= e) return sg[si];
        if(s > r || l > e) return 0;
        
        int m = s + (e - s)/2;
        return getSum(2 * si + 1, l, r, s, m) + getSum(2 * si + 2, l, r, m + 1, e);
    }
public:
    NumArray(vector<int>& nums) {
        v = nums;
        build(0, 0, nums.size() - 1, v);
        n = v.size();
    }
    
    void update(int index, int val) {
        pointUpdate(0, index, 0, n - 1, val);
    }
    
    int sumRange(int left, int right) {
        return getSum(0, left, right, 0, n - 1);
    }
};