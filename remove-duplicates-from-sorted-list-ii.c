**Remove Duplicates from Sorted List II**

Problem Statement 65) Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;  // Handle empty list
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* curr = head;

    while (curr != NULL) {
        while (curr->next != NULL && curr->val == curr->next->val) {
            curr = curr->next;  // Skip duplicates
        }
        if (prev->next == curr) {  // No duplicates encountered
            prev = prev->next;
        } else {
            prev->next = curr->next;  // Remove duplicates
        }
        curr = curr->next;
    }

    return dummy->next;
}



----------------Explanation :-
Purpose:

This code removes all nodes that have duplicate values from a sorted linked list, leaving only distinct values.
Function Breakdown:

Handles Empty List:

Returns NULL if the input list is empty.
Dummy Node Creation:

Allocates a dummy node (dummy) to simplify handling edge cases like removing the head node.
Sets the dummy node's next pointer to the original head.
Pointer Initialization:

Initializes two pointers, prev and curr, to the dummy node and the head, respectively.
Iterating and Removing Duplicates:

Continues as long as curr is not NULL:
Skipping Duplicates:
Iterates while curr->next is not NULL and curr has the same value as its next node.
Moves curr forward, effectively skipping over the duplicates.
Handling No Duplicates:
If prev->next is still curr (no duplicates encountered), moves prev forward to keep it one step behind curr.
Removing Duplicates:
Otherwise, removes duplicates by setting prev->next to curr->next, skipping the nodes with duplicate values.
Advancing Current Pointer:
Moves curr to its next node for the next iteration.
Returning Result:

Returns dummy->next, which is the head of the modified list without duplicates.
Key Points:

Sorted List Requirement: Relies on the list being sorted for this approach to work correctly.
Two-Pointer Technique: Uses two pointers to efficiently identify and remove duplicates in a single pass.
Dummy Node Handling: Simplifies edge cases and avoids special checks for the head node.
Time and Space Complexity: O(n) time complexity due to linear iteration. O(1) space complexity, using only a constant amount of extra space for the dummy node.
