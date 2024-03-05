class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans = "";
        while(word1.size() and word2.size()) {
            if(word1 > word2) {
                ans += word1[0];
                word1 = word1.substr(1);
            }
            else {
                ans += word2[0];
                word2 = word2.substr(1);
            }
        }
        ans += word1;
        ans += word2;
        return ans;
    }
};