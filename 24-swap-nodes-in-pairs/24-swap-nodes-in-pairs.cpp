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
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode *prev=NULL, *curr=head, *next = head->next;
        
        while(next){
            if(prev) prev->next = next;
            else head = next;
            
            curr->next = next->next;
            prev = curr;
            swap(next->next,curr);
            
            if(curr) next = curr->next;
            else break;
        }
        
        return head;
    }
};