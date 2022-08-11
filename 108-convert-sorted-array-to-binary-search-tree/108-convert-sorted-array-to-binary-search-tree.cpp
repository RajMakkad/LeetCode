
class Solution {
public:
    TreeNode* create(int start,int end,vector<int> &arr){
        if(end<start) return NULL;
        int mid = start + (end-start)/2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = create(start,mid-1,arr);
        root->right = create(mid+1,end,arr);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(0,nums.size()-1,nums);
    }
};