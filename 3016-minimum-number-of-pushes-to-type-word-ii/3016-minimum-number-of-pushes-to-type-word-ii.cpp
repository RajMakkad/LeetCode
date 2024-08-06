class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto &i: word)
            freq[i - 'a']++;
        sort(freq.begin(), freq.end());
        int res = 0;
        int count = 0;
        for(int i = 25; i >= 0; i--){
            res += freq[i] * (1 + count/8);
            count++;
        }
        return res;
    }
};