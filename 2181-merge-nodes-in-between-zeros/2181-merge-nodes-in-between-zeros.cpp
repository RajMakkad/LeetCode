class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *node = nullptr, *root = nullptr;
        int sum = 0;
        while(head){
            if(head->val == 0){
                if(sum > 0){
                    if(!root)
                        root = node = new ListNode(sum);
                    else {
                        node->next = new ListNode(sum);
                        node = node->next;
                    }
                    sum = 0;
                }
            }
            sum += head->val;
            head = head->next;
        }
        return root;
    }
};