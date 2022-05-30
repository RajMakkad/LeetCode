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
    ListNode *reverse(ListNode *node, ListNode *&head){
        if(!node) return NULL;
        if(!node->next) return head = node;
        
        ListNode *node1 = reverse(node->next,head);
        node1->next = node;
        node->next = NULL;
        return node;
    }
public:
    ListNode* reverseList(ListNode* head) {
        reverse(head,head);
        return head;
    }
};