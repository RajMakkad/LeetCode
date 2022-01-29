class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st,stnew;
        vector<int> left(n),right(n);

        for(int i = 0;i<n;i++){
            while(!st.empty() and heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }

        st = stnew;

        for(int i = n-1;i>=0;i--){
            while(!st.empty() and heights[i]<=heights[st.top()]) st.pop();
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }

        int ans = 0;

        for(int i = 0;i<n;i++){
            ans = max(ans,(right[i]-left[i]-1)*heights[i]);
        }

        return ans;
        
    }
};