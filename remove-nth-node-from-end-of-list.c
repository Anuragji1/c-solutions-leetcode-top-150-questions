**Remove Nth Node From End of List**

Problem Statement 64) Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

-----------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* fast = dummy;
    struct ListNode* slow = dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }

    // Move both pointers simultaneously until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node from the end
    slow->next = slow->next->next;

    return dummy->next;
}

------------------Explanation :-
Purpose:

This code removes the nth node from the end of a linked list, given the head of the list and the value of n.
Function Breakdown:

Dummy Node Creation:

Allocates a dummy node (dummy) to simplify handling edge cases like removing the head node.
Sets the dummy node's next pointer to the original head.
Pointer Initialization:

Initializes two pointers, fast and slow, both pointing to the dummy node.
Advancing Fast Pointer:

Moves the fast pointer n + 1 steps ahead in the list, creating a gap of n nodes between fast and slow.
Simultaneous Traversal:

Iterates both fast and slow pointers simultaneously until fast reaches the end of the list (becomes NULL). This maintains a gap of n nodes between them.
Removing Node:

When fast reaches the end, slow will be pointing to the node just before the nth node from the end.
Sets slow->next to slow->next->next, effectively removing the nth node from the list.
Returning Result:

Returns the dummy->next, which is now the new head of the modified list.
Key Points:

Two-Pointer Technique: Uses two pointers to efficiently locate the node to be removed without requiring multiple traversals.
Dummy Node Handling: Simplifies edge cases and avoids special checks for the head node.
Time and Space Complexity: O(n) time complexity due to linear iteration. O(1) space complexity, using only a constant amount of extra space for the dummy node.
