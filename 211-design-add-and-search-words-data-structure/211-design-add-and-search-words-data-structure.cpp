class WordDictionary{
    struct Node{
        Node *links[26];
        bool word_end = false; 
        bool is_present(char ch){
            return links[ch - 'a'] != NULL;
        }
        
        Node *get(char ch){
            return links[ch - 'a'];
        }
        
        void insert(char ch){
            links[ch - 'a'] = new Node();
        }
    };
    
    Node *root;
    
public:
    WordDictionary(){
        root = new Node();
    }
    
    void addWord(string word){
        Node *node = root;
        for(auto &s:word){
            if(node->is_present(s) == false){
                node->insert(s);
            }
            node = node->get(s);
        }
        node->word_end = true;
    }
    
    bool match(int index,string &s,Node *node){
        int n = s.length();
        for(int i = index;i<n;i++){
            if(s[i] == '.'){
                for(auto it:node->links){
                    if(it and match(i + 1,s,it)) return true;
                }
                return false;
            }
            else{
                if(!node->is_present(s[i])) return false;
                node = node->get(s[i]);
            }
        }
        
        return node->word_end;
    }
    
    bool search(string s){
        Node *node = root;
        return match(0,s,node);
    }
};