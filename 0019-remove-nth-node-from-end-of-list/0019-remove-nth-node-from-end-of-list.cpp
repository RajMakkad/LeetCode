class Solution {
    int len(ListNode* node){
        if(!node)
            return 0;
        return len(node->next) + 1;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = len(head);
        if(n > size)
            return head;
        if(n == size)
            return head->next;
        ListNode *node = head, *prev = NULL;
        int step = size - n;
        while(step--){
            prev = node;
            node = node->next;
        }
        prev->next = node->next;
        delete node;
        return head;
    }
};