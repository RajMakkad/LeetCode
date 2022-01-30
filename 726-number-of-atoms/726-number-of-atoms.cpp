class Solution {
public:
    string countOfAtoms(string s) {
        map<string,int> atoms;
        stack<int> st;
        int n = s.length();
        int count = 0;
        int mult = 1;

        for(int i = n - 1;i>=0;i--){
            if(isalpha(s[i])){
                if(islower(s[i])){
                    int len = 1;
                    i--;
                    while(i >= 0 and islower(s[i])){
                        i--;
                        len++;
                    }
                    atoms[s.substr(i,len + 1)] += max(count,1)*mult;
                }
                else atoms[s.substr(i,1)] += max(count,1)*mult;

                count = 0;
            }
            else if(isdigit(s[i])){
                int p = 1;
                while(i >= 0 and isdigit(s[i])){
                    count = count + (s[i--] - '0')*p;
                    p = p*10;
                }
                i++;
            }
            else if(s[i] == ')'){
                st.push(mult);
                mult = mult*max(count,1);
                count = 0;
            }
            else{
                mult = st.top();
                st.pop();
            }
        }

        string ans = "";
        for(auto i: atoms){
            ans += i.first;
            if(i.second > 1) ans += to_string(i.second);
        }

        return ans;
    }
};