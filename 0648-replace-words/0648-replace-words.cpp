class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        sort(dictionary.begin(), dictionary.end());
        string ans = "";
        sentence += " ";
        int idx = 0, n = sentence.size();
        while(idx < n){
            int i = idx;
            string sub = "";
            while(sentence[idx] != ' ')
                sub += sentence[idx++];
            bool add = true;
            for(auto root: dictionary)
                if(root == sub.substr(0, root.size())){
                    ans += root;
                    ans += " ";
                    add = false;
                    break;
                }
            if(add){
                ans += sub;
                ans += " ";
            }
            idx++;
        }
        ans.pop_back();
        return ans;
    }
};