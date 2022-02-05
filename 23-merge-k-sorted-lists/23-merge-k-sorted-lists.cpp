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
    ListNode *merge(ListNode *node, ListNode *p){
        if(!node) return p;
        else if(!p) return node;
        
        ListNode *head;
        if(node->val>=p->val){
            head = p;
            head->next = merge(node,p->next);
        }
        else{
            head = node;
            head->next = merge(node->next,p);
        }
        
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        ListNode *node = lists[0];
        
        for(int i = 1;i<n;i++){
            node = merge(node,lists[i]);
        }
        
        return node;
    }
};