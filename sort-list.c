**Sort List**

Problem Statement 102) Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

------------------------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode *mergeList(struct ListNode *l1, struct ListNode *l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->val <= l2->val)
    {
        l1->next = mergeList(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeList(l1, l2->next);
        return l2;
    }
}

struct ListNode* sortList(struct ListNode* head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    struct ListNode *fast, *slow, *pre;
    fast = slow = head;
    while(fast && fast->next)
    {
        pre = slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    pre->next = NULL;
    return mergeList(sortList(head), sortList(slow));
}

------------Explanation :- 
This code implements the sortList function, which sorts a singly-linked list in ascending order using the Merge Sort algorithm.

Steps:

Base Cases:

If the head is NULL or has only one node (no sorting needed), return the head as it already represents a sorted list.
Find the Middle Node:

Use two pointers, fast and slow:
fast moves two steps at a time (fast->next->next).
slow moves one step at a time (slow->next).
When fast reaches the end or the second-to-last node (depending on list length), slow will be pointing to the middle node.
Split the List:

Set the next pointer of the node before the middle node (pre) to NULL. This effectively splits the list into two halves: the first half from head to the middle node and the second half from the node after the middle node to the end.
Recursive Calls:

Recursively call sortList on both halves of the list:
sortList(head) sorts the first half.
sortList(slow) sorts the second half.
Merge the Sorted Halves:

Call the mergeList function with the sorted first half (returned by the first recursive call) and the sorted second half (returned by the second recursive call).
The mergeList function merges the two sorted halves into a single sorted list and returns the head of the merged list.
mergeList Function:

This helper function takes two sorted linked lists and merges them into a single sorted list.
It iterates through both lists and compares the heads of each.
The smaller element is appended to the result list, and the corresponding pointer is advanced.
This process continues until one of the lists becomes empty.
The remaining elements from the non-empty list are then appended to the end of the result list.
