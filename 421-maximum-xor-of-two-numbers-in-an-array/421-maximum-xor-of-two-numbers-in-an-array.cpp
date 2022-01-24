class Solution {
    struct Node{
        Node *links[2];
        
        bool is_present(int p){
            return links[p] != NULL;
        }
        
        void insert(int p){
            links[p] = new Node();
        }
        
        Node *get(int p){
            return links[p];
        }
    };
    
    Node *root = new Node();
    
    void add(int num){
        Node *node = root;
        for(int i = 31;i>=0;i--){
            int p = (num>>i)&1;
            
            if(node->is_present(p) == false){
                node->insert(p);
            }
            node = node->get(p);
        }
    }
    
    int getXor(int num){
        Node *node = root;
        int ans = 0;
        
        for(int i = 31;i>=0;i--){
            int p = (num>>i)&1;
            if(node->is_present(!p)){
                ans |= 1<<i;
                node = node->get(!p);
                continue;
            }
            
            node = node->get(p);
        }
        
        return ans;
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        for(auto &i:nums) add(i);
        int ans = 0;
        
        for(auto &i:nums){
            ans = max(ans,getXor(i));
        }
        
        return ans;
    }
};














