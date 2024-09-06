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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> vis(begin(nums), end(nums));
        ListNode* dummy = new ListNode(0), *curr = dummy;
        curr->next = head;
        while(curr->next)
        {
            if(vis.count(curr->next->val)) curr->next = curr->next->next;
            else curr = curr->next;
        }
        return dummy->next;
    }
};