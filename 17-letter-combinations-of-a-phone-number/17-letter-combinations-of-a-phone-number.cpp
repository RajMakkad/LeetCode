class Solution {
    void generate(int &index,string &digits,vector<string> &map,string &sub,vector<string> &ans){
        int n = digits.length();
        if(index>=n){
            ans.push_back(sub);
            return ;
        }
        
        int i = digits[index] - '2';
        for(auto ch:map[i]){
            sub.push_back(ch);
            index++;
            generate(index,digits,map,sub,ans);
            index--;
            sub.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> map = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string sub = "";
        int index = 0;
        
        generate(index,digits,map,sub,ans);
        return ans;
    }
};