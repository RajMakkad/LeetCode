class Solution {
    bool check(char c, vector<string> &words) {
        for (auto &word : words) {
            auto it = find(word.begin(), word.end(), c);
            if (it == word.end())
                return false;
            word.erase(it);
        }
        return true;
    }
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        string firstWord = words[0];
        for (char c : firstWord) {
            if (check(c, words))
                ans.push_back(string(1, c));
        }
        return ans;
    }
};