class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = 0;
        stack<int> st;
        vector<int> dp(n + 1,0);

        for(int i = 1;i<=n;i++){
            if(s[i - 1] == '(') st.push(i);
            else if(!st.empty()) {
                int x = st.top(); st.pop();
                int y = i - x + 1 + dp[x - 1];
                dp[i] = y;
                ans = max(ans,dp[i]);
            }
        }

        return ans;
    }
};