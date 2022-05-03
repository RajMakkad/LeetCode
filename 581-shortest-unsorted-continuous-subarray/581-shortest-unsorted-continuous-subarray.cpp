class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int start = n;

        for(int i = 0;i<n;i++){
            while(st.size() and nums[st.top()] > nums[i]){
                start = min(start,st.top());
                st.pop();
            }

            st.push(i);
        }

        int end = 0;
        st = stack<int>();
        for(int i = n - 1;i>=0;i--){
            while(st.size() and nums[i] > nums[st.top()]){
                end = max(end,st.top());
                st.pop();
            }

            st.push(i);
        }

        return (end > start ? (end - start + 1) : 0);
    }
};
