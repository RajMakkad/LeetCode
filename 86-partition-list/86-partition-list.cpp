class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        
        ListNode *s1 = NULL, *s2 = NULL;
        
        ListNode *node = head, *nextHead = NULL;
        
        while(node){
            if(node->val < x){
                if(!s1) s1 = head = node;
                else {
                    s1->next = node;
                    s1 = s1->next;
                }
            }
            else {
                if(!s2) s2 = nextHead = node;
                else {
                    s2->next = node;
                    s2 = s2->next;
                }
            }
            
            node = node->next;
        }
        
        if(!s1) head = nextHead;
        else s1->next = nextHead;
        
        if(s2) s2->next = NULL;
        
        return head;
    }
};