class Solution {
    int length(ListNode *node){
        if(!node) return 0;
        return length(node->next) + 1;
    }
public:
    ListNode* rotateRight(ListNode* head, int k){
        if(!head) return head;
        
        int n = length(head);
        k = k%n;
        
        if(!k) return head;
        
        ListNode *node = head, *pre = NULL;
        int cnt = n - k;
        while(cnt--){
            pre = node;
            node = node->next; 
        }
        
        ListNode *c = head;
        head = node;
        while(node->next) node = node->next;
        
        node->next = c;
        pre->next = NULL;
        
        return head;
    }
};