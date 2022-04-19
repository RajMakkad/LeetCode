class Solution {
    void inorder(TreeNode *node,vector<int> &order){
        if(!node) return ;
        inorder(node->left,order);
        
        order.push_back(node->val);
        
        inorder(node->right,order);
    }
    
    void recover(TreeNode *node,vector<int> &order,int &i){
        if(!node) return ;
        recover(node->left,order,i);
        if(order[i] != node->val) swap(node->val,order[i]);
        i++;
        
        recover(node->right,order,i);
    }
public:
    void recoverTree(TreeNode* root) {
        TreeNode *node = root;
        
        vector<int> order;
        inorder(node,order);
        
        sort(order.begin(),order.end());
        
        node = root;
        int i = 0;
        
        recover(node,order,i);
    }
};