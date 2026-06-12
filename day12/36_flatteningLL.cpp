/*
Flattening a Linked List

Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

‘Next’ points to the next node in the list
‘Child’ pointer to a linked list where the current node is the head

Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.
Example:

Input:
3 -> 2 -> 1 -> 4 -> 5
     |    |    |    |
     10   7    9    6
          |         |
          11        8
          |
          12

Output:
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12

Explanation:
Each node's child pointer represents a sorted linked list. After merging all the sorted child lists and removing the horizontal (next)
structure, we obtain a single flattened linked list containing all nodes in ascending order.
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode* child;

    ListNode(int data) {
        val = data;
        next = NULL;
        child = NULL;
    }
};

class Solution {
public:

    // merging two sorted child linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->child = list1;
                list1 = list1->child;
            } else {
                temp->child = list2;
                list2 = list2->child;
            }
            temp = temp->child;
            // removing old horizontal links
            temp->next = NULL;
        }

        // attaching remaining nodes
        if (list1 != NULL) {
            temp->child = list1;
        } else {
            temp->child = list2;
        }
        return dummy->child;
    }

    ListNode* flattenLinkedList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        // flattening the right side first
        ListNode* rightHead = flattenLinkedList(head->next);
        // merging current list with flattened right side
        return merge(head, rightHead);
    }
};

void printFlattened(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

int main() {

    /*
        5 --------> 10 --------> 19 --------> 28
        |            |           |            |
        7            20          22           35
        |                        |            |
        8                        50           40
        |                                     |
        30                                    45
    */

    ListNode* head = new ListNode(5);
    head->child = new ListNode(7);
    head->child->child = new ListNode(8);
    head->child->child->child = new ListNode(30);

    head->next = new ListNode(10);
    head->next->child = new ListNode(20);

    head->next->next = new ListNode(19);
    head->next->next->child = new ListNode(22);
    head->next->next->child->child = new ListNode(50);

    head->next->next->next = new ListNode(28);
    head->next->next->next->child = new ListNode(35);
    head->next->next->next->child->child = new ListNode(40);
    head->next->next->next->child->child->child = new ListNode(45);

    Solution obj;
    ListNode* flattenedHead = obj.flattenLinkedList(head);
    cout << "Flattened Linked List: ";
    printFlattened(flattenedHead);

    return 0;
}