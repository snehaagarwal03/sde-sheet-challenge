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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;    // prev node initially points to NULL
        ListNode* curr = head;       // current node points to head

        while(curr != nullptr) {
            ListNode* nextNode = curr->next;   // storing next node before changing 
            curr->next = prev;      // reversing current node's pointer
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};