class Solution {
public:
    int calculate(string s) {
        s += '+';
        int n = s.length();
        char sign = '+';
        stack<int> st;
        long long sum = 0;
        
        for(int i = 0;i<n;i++){
            if(isdigit(s[i])){
                sum = sum*10 + (s[i] - '0');
            }
            else if(s[i] != ' '){
                if(sign == '+') st.push(sum);
                else if(sign == '-') st.push(-sum);
                else if(sign == '*'){
                    sum = sum*st.top();
                    st.pop();
                    st.push(sum);
                }
                else{
                    sum = st.top()/sum;
                    st.pop();
                    st.push(sum);
                }
                
                sum = 0;
                sign = s[i];
            }
        }
        
        while(st.size()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};