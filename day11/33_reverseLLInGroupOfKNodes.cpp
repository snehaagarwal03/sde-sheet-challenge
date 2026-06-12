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
    // returns the kth node starting from temp
    ListNode* getKthNode(ListNode* temp, int k) {
        k--;
        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // dummy node helps handle edge cases easily
        ListNode* dummy = new ListNode();
        dummy->next = head;

        // prevGroupEnd points to the node before current group
        ListNode* prevGroupEnd = dummy;
        while (true) {
            // find the kth node of the current group
            ListNode* kNode = getKthNode(prevGroupEnd->next, k);
            // if fewer than k nodes remain, stop
            if (kNode == NULL) break;
            // storing the node after the group
            ListNode* nextGroupStart = kNode->next;
            ListNode* prev = nextGroupStart;
            ListNode* curr = prevGroupEnd->next;

            while (curr != nextGroupStart) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // current group's first node becomes the last node after reversal
            ListNode* groupStart = prevGroupEnd->next;
            // connect previous group with reversed group
            prevGroupEnd->next = kNode;
            // move prevGroupEnd to end of reversed group
            prevGroupEnd = groupStart;
        }
        return dummy->next;     
    }
};