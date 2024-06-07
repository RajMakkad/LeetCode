class Trie {
    public:
    Trie *child[26];
    bool is_end;
    Trie(){
        for(int i = 0;i < 26;i++)
            child[i] = nullptr;
        is_end = false;
    }
};

class Solution {
public:
    Trie *root = new Trie();
    void insert(string &word){
        Trie *node = root;
        for(auto w: word){
            int ch = w - 'a';
            if(node->child[ch] == nullptr)
                node->child[ch] = new Trie();
            node = node->child[ch];
        }
        node->is_end = true;
    }
    string getRoot(string &word){
        Trie *node = root;
        string res = "";
        for(auto w: word){
            int ch = w - 'a';
            if(node->child[ch] == nullptr)
                return word;
            res += w;
            node = node->child[ch];
            if(node->is_end == true)
                return res;
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto root: dictionary)
            insert(root);
        string ans = "", sub = "";
        sentence += " ";
        for(int i = 0; i < sentence.length();i++){
            if(sentence[i] == ' '){
                if((int)ans.size() > 0) ans += " ";
                ans += getRoot(sub);
                sub = "";
            }
            else sub += sentence[i];
        }
        return ans;
    }
};