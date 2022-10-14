class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *pre = NULL, *slow = head, *fast = head;
        
        while(fast and fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *next = slow->next;
        delete(slow);
        
        if(pre) pre->next = next;
        else head = next;
        
        return head;
    }
};