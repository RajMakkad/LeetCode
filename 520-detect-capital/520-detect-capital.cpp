class Solution {
public:
    bool detectCapitalUse(string word){
        int n = word.length();
        int up = 0;

        for(int i = 0;i<n;i++){
            if(isupper(word[i])) up++;
        }

        return up == 0 || up == n || (up == 1 and isupper(word[0]));
    }
};