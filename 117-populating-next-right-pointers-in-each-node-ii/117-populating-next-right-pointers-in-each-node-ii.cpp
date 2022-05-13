class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node *> q;
        q.push(root);
        
        while(q.size()){
            int size = q.size();
            Node *next = NULL;
            while(size--){
                Node *node =q.front();
                q.pop();
                node->next = next;
                next = node;
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        
        return root;
    }
};