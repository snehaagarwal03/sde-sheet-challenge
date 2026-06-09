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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);   //dummy node for merging
        ListNode* temp = dummy;    //temp always point to the last node of merged list

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if(list1 != nullptr) {  //attaching remaining nodes
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        return dummy->next;     //return merged list (skip dummy node) 
    }
};