class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        
        while(q.size()){
            Node* next = NULL;
            int s = q.size();
            while(s--){
                Node* curr = q.front();
                q.pop();
                curr->next = next;
                next = curr;
                if(curr->right) q.push(curr->right);
                if(curr->left) q.push(curr->left);
            }
        }
        
        return root;
    }
};