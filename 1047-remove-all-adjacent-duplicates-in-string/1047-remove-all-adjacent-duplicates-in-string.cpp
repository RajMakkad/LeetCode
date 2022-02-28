class Solution {
public:
    string removeDuplicates(string s){
        int n = s.length();
        string ans = "";
        ans += s[0];

        for(int i = 1;i<n;i++){
            if(s[i] == ans.back()) ans.pop_back();
            else ans += s[i];
        }

        return ans;
    }
};