class Solution {
    int size(ListNode *head){
        if(!head) return 0;
        return size(head->next) + 1;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = size(head);
        if(n == 1) return head;
        
        ListNode *pre1 = NULL, *curr1 = head, *pre2 = NULL, *curr2 = head; 
        int p = k - 1;
        while(p--){
            pre1 = curr1;
            curr1 = curr1->next;
        }
        
        p = n - k;
        while(p--){
            pre2 = curr2;
            curr2 = curr2->next;
        }
        
        ListNode *next1 = curr1->next, *next2 = curr2->next;
        if(curr1->next == curr2){
            if(pre1) pre1->next = curr2;
            curr2->next = curr1;
            curr1->next = next2;
        }
        else if(curr2->next == curr1){
            if(pre2) pre2->next = curr1;
            curr1->next = curr2;
            curr2->next = next1;
        }
        else{
             if(pre1) pre1->next = curr2;
             curr2->next = next1;

             if(pre2) pre2->next = curr1;
             curr1->next = next2;
        }
        
        
        if(k == 1) head = curr2;
        if(k == n) head = curr1;
        
        return head;
    }
};