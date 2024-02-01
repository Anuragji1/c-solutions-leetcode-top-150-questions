**Reverse Linked List II**

Problem Statement 62) Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

-----------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    // Handle edge cases and find the nodes before and at the left boundary
    if (left == right) return head;  // No need to reverse
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    for (int i = 1; i < left; i++) {
        prev = prev->next;
    }

    // Reverse the sublist within the boundaries
    struct ListNode* start = prev->next;
    struct ListNode* then = start->next;
    for (int i = left; i < right; i++) {
        start->next = then->next;
        then->next = prev->next;
        prev->next = then;
        then = start->next;
    }

    return dummy->next;
}


------------------------Explanation :-
Purpose:

This code reverses a specific portion of a linked list, given the starting and ending indices (left and right) of the sublist to be reversed.
Function Breakdown:

Handles Edge Cases:

If left equals right, no reversal is needed, so it returns the original head.
Creates Dummy Node:

Allocates a dummy node (dummy) to simplify handling the head of the list during reversal.
Sets the dummy node's next pointer to the original head.
Finds Left Boundary Node:

Iterates left - 1 times to find the node (prev) before the start of the sublist to be reversed.
Reverses Sublist:

Initializes start to the first node of the sublist to be reversed.
Initializes then to the second node of the sublist.
Iterates from left to right - 1 to reverse the links:
Temporarily stores the next node after then.
Reverses the link between start and then.
Reverses the link between prev and then.
Updates the pointers for the next iteration.
Returns Result:

Returns the head of the list, which might be the dummy node or the original head, depending on whether the reversal started at the first node.
Key Points:

Iterative Reversal: Reverses the sublist in-place without recursion.
Dummy Node: Simplifies handling by avoiding special cases for the head node.
Time and Space Complexity: O(n) time complexity, where n is the length of the list, due to linear iteration. O(1) space complexity, using only a constant amount of extra space for the dummy node.
