class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while(j > i)
            swap(s[i++], s[j--]);
    }
};