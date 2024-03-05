class Solution {
public:
    int minimumLength(string str) {
        int n = str.length();
        int s = 0, e = n - 1;
        while(e > s and str[s] == str[e]){
            char c = str[s];
            while(s <= e and str[s] == c)
                s++;
            while(e >= s and str[e] == c)
                e--;
        }
        return e - s + 1;
    }
};