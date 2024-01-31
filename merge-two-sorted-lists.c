**Merge Two Sorted Lists**

Problem Statement) You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

-------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = dummyHead;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = (list1 != NULL) ? list1 : list2;

    return dummyHead->next;
}

-------------------------------Explanation:- 
  Purpose:

This code merges two sorted linked lists, resulting in a single sorted linked list containing all elements from both input lists in ascending order.
Function Breakdown:

Initialization:

Creates a dummy head node (dummyHead) to simplify the merging process.
Initializes a pointer (current) to the dummy head.
Iterating and Merging:

Iterates as long as both list1 and list2 have nodes:
Compares the values of the current nodes in list1 and list2.
Appends the node with the smaller value to the merged list.
Advances the pointers (current, list1, or list2) accordingly.
Appending Remaining Nodes:

After one of the lists becomes empty, appends any remaining nodes from the other list to the merged list.
Returning Result:

Returns the head of the merged list, skipping the dummy head.
Key Points:

Iterative Merging: Merges the lists in a single pass without recursion.
Dummy Node: Simplifies handling the start of the merged list and potential edge cases.
Time and Space Complexity: O(n + m) time complexity, where n and m are the lengths of the lists, due to linear iteration. O(1) space complexity, using only a constant amount of extra space for the dummy node.
