class Solution {
public:
    bool checkValidString(string s){
        int n = s.length();
        vector<int> braces,star;
        
        for(int i = 0;i<n;i++){
            if(s[i] == '(') braces.push_back(i);
            else if(s[i] == '*') star.push_back(i);
            else{
                if(braces.size()) braces.pop_back();
                else if(star.size()) star.pop_back();
                else return false;
            }
        }
        
        while(star.size() and braces.size() and star.back() > braces.back()){
            star.pop_back();
            braces.pop_back();
        }
        
        return braces.empty();
    }
};