class Solution {
    bool ispalindrome(int s,int e,string &str){
        while(e > s){
            if(str[s] != str[e]) return false;
            s++;
            e--;
        }
        return true;
    }
public:
    bool validPalindrome(string str) {
        int n = str.length();
        int s = 0;
        int e = n - 1;
        int cnt = 0;
        
        while(e > s){
            if(str[s] != str[e]){
                if(ispalindrome(s + 1,e,str) || ispalindrome(s,e - 1,str)) return true;
                else return false;
            }
            s++;
            e--;
        }
        
        return true;
    }
};