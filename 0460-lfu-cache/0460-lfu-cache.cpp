#define ff first
#define ss second

class LFUCache {
    struct Node{
        Node *next, *prev;
        int key, value, freq;
    };
    
    int capacity, minfreq, curr;
    unordered_map<int, pair<Node*, Node*>> freqList;
    unordered_map<int, Node*> keyAdd;
    
    void disconnect(Node *node){
        Node *x = node->prev;
        Node *y = node->next;
        x->next = y;
        y->prev = x;
        
        int freq = node->freq;
        auto p = freqList[freq];
        x = p.ff;
        y = p.ss;
        
        if(x->next == y){
            freqList.erase(freq);
            if(minfreq == freq) 
                minfreq++;
        }
    }
    
    void connect(Node *node){
        Node* end = freqList[node->freq].ss;
        
        end->prev->next = node;
        node->prev = end->prev;
        
        node->next = end;
        end->prev = node;
    }
    
    void createList(int freq){
        Node *x = new Node();
        Node *y = new Node();

        x->next = y;
        y->prev = x;

        freqList[freq] = {x, y};
    }
    
    void updateNode(Node* node){
        disconnect(node);
        int freq = node->freq + 1;
        
        if(freqList.find(freq) == freqList.end()){
            createList(freq);
        }
        
        node->freq = freq;
        connect(node);
    }
    
public:
    
    LFUCache(int cap) {
        capacity = cap;
        curr = 0;
        minfreq = 0;
    }
    
    int get(int key) {
        if(keyAdd.find(key) == keyAdd.end())
            return -1;
        
        updateNode(keyAdd[key]);
        return keyAdd[key]->value;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return ;
        if(keyAdd.find(key) != keyAdd.end()){
            Node *node = keyAdd[key];
            node->value = value;
            
            updateNode(node);
        }
        else {
            
            Node *node;
            if(curr == capacity){
                node = freqList[minfreq].ff->next;
                disconnect(node);
                keyAdd.erase(node->key);
            }
            else curr++;
            
            node = new Node();
            node->key = key;
            node->value = value;
            node->freq = 1;
            
            keyAdd[key] = node;
            
            if(freqList.find(1) == freqList.end()){
                createList(1);
            }
            
            connect(node);
            
            minfreq = 1;
        }
    }
};

