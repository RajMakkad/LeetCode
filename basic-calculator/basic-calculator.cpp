class Solution {
public:
    int calculate(string s) {
        int n = s.length();

        stack<pair<int,int>> st;
        int sign = 1;
        long long int sum = 0;

        for(int i = 0;i<n;i++){
            if(isdigit(s[i])){
                int num = 0;
                while(i<n and isdigit(s[i])){
                    num = num*10 + (s[i] - '0');
                    i++;
                }

                sum += num*sign;
                sign = 1;
                i--;
            }
            else if(s[i]=='('){
                st.push({sum,sign});
                sum = 0;
                sign = 1;
            }
            else if(s[i]==')'){
                sum = st.top().first + st.top().second*sum;
                st.pop();
            }
            else if(s[i]=='-') sign = -1;
        }

        return sum;
    }
};