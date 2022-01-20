class Trie {
    struct Node{
        bool word_end = false;
        Node *links[26];
        
        bool is_present(char ch){
            return links[ch - 'a'] != NULL;
        }
        
        void create(char ch){
            links[ch - 'a'] = new Node();
        }
        
        Node *get(char ch){
            return links[ch - 'a'];
        }
        
        void setEnd(){
            word_end = true; 
        }
        
        bool is_end(){
            return word_end;
        }
    };
    
    Node *root;
    
public:
    
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node *node = root;
        for(int i = 0;i<word.length();i++){
            if(node -> is_present(word[i]) == false){
                node -> create(word[i]);
            }
            
            //node = node -> links[word[i] - 'a'];
            node = node -> get(word[i]);
        }
        
        //node -> word_end = true;
        node -> setEnd();
    }
    
    bool search(string word){
        Node *node = root;
        for(int i = 0;i<word.length();i++){
            if(node -> is_present(word[i]) == false) return false;
            
            //node = node -> links[word[i] - 'a'];
            node = node -> get(word[i]);
        }
        
        // return node -> word_end;
        return node -> is_end();
    }
    
    bool startsWith(string prefix){
        Node *node = root;
        for(int i = 0;i<prefix.length();i++){
            if(node -> is_present(prefix[i]) == false) return false;
            
            //node = node -> links[prefix[i] - 'a'];
            node = node -> get(prefix[i]);
        }
        
        return true;
    }
};