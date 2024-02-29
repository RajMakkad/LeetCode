class Solution {
    bool solve(TreeNode* node, int level, vector<int> &prev){
        if(!node)
            return true;
        bool ans = level % 2 == 0 ? node->val % 2 == 1 : node->val % 2 == 0;
        if(prev.size() == level) {
            prev.push_back(node->val);
        }   
        else {
            if(level % 2)
                ans &= (prev[level] > node->val);
            else 
                ans &= (prev[level] < node->val);
            prev[level] = node->val;
        }
        return ans & solve(node->left, level + 1, prev) & solve(node->right, level + 1, prev);
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        vector<int> prev;
        return solve(root, level, prev);
    }
};