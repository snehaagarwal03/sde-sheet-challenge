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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;    //length of linked list
        ListNode* temp = head;
        while(temp != nullptr) {
            l++;
            temp = temp->next;
        }

        //if head node needs to be deleted
        if(l == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        //moving to the previous node of the node of the list to be deleted
        //(5-2 = 3) that means for deleting 4th node you need to access 3rd node
        int prevNode = l - n;
        temp = head;   //point temp back to first node

        //at the 2nd iteration temp reaches the 3rd node that's why we have done
        //i < prevNode and not i <= prevNode
        for(int i = 1; i < prevNode; i++) {
            temp = temp->next;
        }

        //now this will delete the nth node from the end
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;   
    }
};