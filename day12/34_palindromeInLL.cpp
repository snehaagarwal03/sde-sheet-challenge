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
    bool isPalindrome(ListNode* head) {
        // always a palindrome
        if(head == NULL || head->next == NULL) {
            return true;
        }

        // finding middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reversing the second half starting from slow
        ListNode* prev = NULL;
        ListNode* curr = slow;
        while(curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // prev now points to the head of reversed second half
        ListNode* first = head;
        ListNode* second = prev;
        // comparing both halves
        while(second != NULL) {
            if(first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }
        return true;       
    }
};