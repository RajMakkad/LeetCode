class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int> st;

        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                st.push(cnt);
                cnt = 0;
            }
            else{
                if(cnt == 0){
                    cnt++;
                    if(!st.empty()) cnt += st.top();
                }
                else if(!st.empty()) cnt = (2*cnt + st.top());

                st.pop();
            }
        }

        return cnt;
    }
};