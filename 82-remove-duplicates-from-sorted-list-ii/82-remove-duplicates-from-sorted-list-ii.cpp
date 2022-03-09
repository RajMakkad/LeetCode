class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        
        ListNode *pre = NULL, *curr = head, *next = curr->next;
        
        while(next){
            if(curr->val == next->val){
                while(next and curr->val == next->val) next = next->next;
                if(pre == NULL) head = next;
                else pre->next = next;
            }
            else pre = curr;
            curr = next;
            if(curr) next = curr->next;
        }
        
        return head;
    }
};