/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void reverse(ListNode *s, ListNode *e){
        if(s == e) return ;
        reverse(s->next, e);
        
        s->next->next = s;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *s = head, *e = head, *pre = NULL, *next = NULL;
        int x = left;
        left--, right--;
        
        while(left--) pre = s, s = s->next;
        while(right--) e = e->next;
        
        next = e->next;
        
        reverse(s, e);
        
        s->next = next;
        if(pre == NULL) head = e;
        else pre->next = e;
        
        return head;
    }
};