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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx = 0;
        vector<int> critical;
        while(head and head->next and head->next->next){
            if(head->val > head->next->val and head->next->val < head->next->next->val)
                critical.push_back(idx);
            if(head->val < head->next->val and head->next->val > head->next->next->val)
                critical.push_back(idx);
            idx++;
            head = head->next;
        }
        if(critical.size() <= 1)
            return {-1, -1};
        vector<int> ans = {1000000000, critical.back() - critical[0]};
        for(int i = 1; i < critical.size(); i++)
            ans[0] = min(ans[0], critical[i] - critical[i - 1]);
        return ans;
    }
};