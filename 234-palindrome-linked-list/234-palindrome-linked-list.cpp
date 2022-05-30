class Solution {
    ListNode *reverse(ListNode *node){
        ListNode *pre = NULL;
        while(node){
            ListNode *next = node->next;
            node->next = pre;
            pre = node;
            node = next;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        ListNode *dummy = head;
        
        while(slow){
            if(slow->val != dummy->val) return false;
            slow = slow->next;
            dummy = dummy->next;
        }
        
        return true;
    }
};