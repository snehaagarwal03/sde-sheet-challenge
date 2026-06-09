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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;    //using tortoise and hare algo
        ListNode* fast = head;

        while(fast && fast->next) {    //slow moves 1 step and fast moves 2 steps
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;     //slow reached middle node  
    }
};