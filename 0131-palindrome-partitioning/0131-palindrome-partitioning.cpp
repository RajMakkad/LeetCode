class Solution {
    bool is_palindrome(int s, int e, string &str){
        while(e > s) {
            if(str[s++] != str[e--])
                return false;
        }
        return true;
    }
    void palindrome_partition(int s, vector<vector<string>> &ans, vector<string> sub, string &str){
        int n = str.length();
        if(s >= n) {
            ans.push_back(sub);
        } else {
            for(int i = s;i < n;i++){
                if(is_palindrome(s, i, str)) {
                    sub.push_back(str.substr(s, i - s + 1));
                    palindrome_partition(i + 1, ans, sub, str);
                    sub.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        palindrome_partition(0, ans, sub, s);
        
        return ans;
    }
};