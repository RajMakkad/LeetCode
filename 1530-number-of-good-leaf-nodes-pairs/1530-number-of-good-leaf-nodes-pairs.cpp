class Solution {
    void fetchLeafs(TreeNode *node, TreeNode *prev, unordered_set<TreeNode*> &leaf, unordered_map<TreeNode*, vector<TreeNode*>> &nodes){
        if(!node)
            return ;
        if(prev) {
            nodes[prev].push_back(node);
            nodes[node].push_back(prev);
        }
        if(!node->left and !node->right){
            leaf.insert(node);
        }
        fetchLeafs(node->left, node, leaf, nodes);
        fetchLeafs(node->right, node, leaf, nodes);
    }
    void pairs(TreeNode *node, TreeNode *prev, unordered_set<TreeNode*> &leaf, int distance, unordered_map<TreeNode*, vector<TreeNode*>> &nodes, int &ans){
        if(!node)
            return ;
        if(distance < 0)
            return ;
        if(leaf.find(node) != leaf.end())
            ans++;
        for(auto &i: nodes[node]){
            if(prev != i)
                pairs(i, node, leaf, distance - 1, nodes, ans);
        }
    }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> nodes;
        unordered_set<TreeNode*> leaf;
        fetchLeafs(root, nullptr, leaf, nodes);
        int ans = 0;
        for(auto &i: leaf) {
            pairs(i, nullptr, leaf, distance, nodes, ans);
        }
        return (ans - (int)leaf.size()) / 2;
    }
};