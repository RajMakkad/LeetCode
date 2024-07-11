class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string res = "";
        for(auto &i: s){
            if(i == '('){
                st.push(res);
                res = "";
            }
            else if(i == ')'){
                reverse(res.begin(), res.end());
                res = st.top() + res;
                st.pop();
            }
            else 
                res += i;
        }
        return res;
    }
};