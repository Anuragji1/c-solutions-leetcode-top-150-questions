**Rotate List**

Problem Statement 66) Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

----------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) return head;  // Handle edge cases

    int len = 1;  // Length of the list
    struct ListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    k %= len;  // Adjust k to be within the list's length
    if (k == 0) return head;  // No rotation needed

    struct ListNode* newTail = head;
    for (int i = 1; i < len - k; i++) {
        newTail = newTail->next;
    }

    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

------------Explanation :-
Purpose:

This code rotates a linked list to the right by k positions, effectively moving the last k nodes to the beginning while maintaining their relative order.
Function Breakdown:

Handles Edge Cases:

Returns the original head if:
The list is empty (head == NULL)
The list has only one node (head->next == NULL)
No rotation is needed (k == 0)
Calculates List Length:

Initializes a tail pointer to the head and a len variable to 1.
Iterates through the list to find the tail and count the nodes, updating len accordingly.
Adjusts k for List Length:

Calculates k % len to ensure k is within the valid range of the list's length.
Returns the original head if k is 0 after adjustment (no rotation needed).
Finds New Tail:

Initializes a newTail pointer to the head.
Iterates len - k times to move newTail to the node that will become the new tail after rotation.
Performs Rotation:

Sets newHead to newTail->next, which will become the new head of the rotated list.
Disconnects the tail from the list by setting newTail->next to NULL.
Connects the original tail to the original head, making the list circular.
Returns New Head:

Returns newHead, which is now the head of the rotated list.
Key Points:

In-Place Rotation: Modifies the list in-place without creating a new list.
Single Traversal: Achieves rotation in a single traversal of the list.
Time and Space Complexity: O(n) time complexity due to linear traversal. O(1) space complexity, using only a constant amount of extra space for pointers.
