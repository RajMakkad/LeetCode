class Solution {
    int getlength(ListNode *head){
        if(!head) return 0;
        return getlength(head->next) + 1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = getlength(headA);
        int m = getlength(headB);
        
        for(int i = n - m;i>0;i--) headA = headA->next;
        for(int i = m - n;i>0;i--) headB = headB->next;
        
        for(int i = min(n,m);i>0;i--){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};