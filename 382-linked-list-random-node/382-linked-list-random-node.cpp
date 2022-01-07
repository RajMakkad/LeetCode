class Solution {
    vector<int> nodes;
public:
    Solution(ListNode* head) {
        while(head){
            nodes.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        int n = nodes.size();
        int index = rand()%n;
        return nodes[index];
    }
};