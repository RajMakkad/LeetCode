class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1;i>=0;i--){
            int count = 0;
            while(st.size() and heights[i] >= heights[st.top()]){
                st.pop();
                count++;
            }

            ans[i] = count;
            if(st.size()) ans[i]++;
            st.push(i);
        }

        return ans;
    }
};