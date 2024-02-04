**partition List**

Problem Statement 67) Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

----------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* beforeStart = NULL;
    struct ListNode* beforeEnd = NULL;
    struct ListNode* afterStart = NULL;
    struct ListNode* afterEnd = NULL;

    while (head != NULL) {
        struct ListNode* next = head->next;
        head->next = NULL;  // Disconnect the node
        if (head->val < x) {
            if (beforeStart == NULL) {
                beforeStart = head;
                beforeEnd = head;
            } else {
                beforeEnd->next = head;
                beforeEnd = head;
            }
        } else {
            if (afterStart == NULL) {
                afterStart = head;
                afterEnd = head;
            } else {
                afterEnd->next = head;
                afterEnd = head;
            }
        }
        head = next;
    }

    if (beforeStart == NULL) {
        return afterStart;  // All nodes are greater than or equal to x
    }

    beforeEnd->next = afterStart;
    return beforeStart;
}

---------------------Explamation :-
Purpose:

This code partitions a linked list around a given value x, such that all nodes with values less than x come before all nodes with values greater than or equal to x. The relative order within each partition is preserved.
Function Breakdown:

Pointer Initialization:

Initializes four pointers:
beforeStart: Tracks the start of the "before" partition (nodes with values less than x).
beforeEnd: Tracks the end of the "before" partition.
afterStart: Tracks the start of the "after" partition (nodes with values greater than or equal to x).
afterEnd: Tracks the end of the "after" partition.
Iterating Through List:

Iterates through the list using a while loop:
Disconnecting Node: Temporarily disconnects the current node from the list by setting head->next = NULL.
Checking Value and Placing Node:
If head->val < x:
Adds the node to the "before" partition by updating beforeStart and beforeEnd pointers accordingly.
Otherwise:
Adds the node to the "after" partition by updating afterStart and afterEnd pointers.
Moving to Next Node: Moves head to the next node in the original list.
Handling Edge Case:

If beforeStart is still NULL after the loop, it means all nodes were greater than or equal to x. Returns afterStart as the new head.
Connecting Partitions:

Connects the "before" and "after" partitions by setting beforeEnd->next to afterStart.
Returns beforeStart as the head of the partitioned list.
Key Points:

In-Place Partitioning: Modifies the list in-place without creating new lists.
Single Traversal: Achieves partitioning in a single traversal of the list.
Time and Space Complexity: O(n) time complexity due to linear traversal. O(1) space complexity, using only a constant amount of extra space for pointers.
