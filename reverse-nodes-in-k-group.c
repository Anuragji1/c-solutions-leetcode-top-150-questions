**Reverse Nodes in k-Group**

Problem Statement 63) Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
-----------------------------------------------------------------------------------------
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

--------------------Explanation :-
Here's a detailed explanation of the reverseBetween function, incorporating key points and additional insights:

Purpose:

Reverses a specific portion of a linked list, given the starting and ending indices (left and right) of the sublist to be reversed.
Function Breakdown:

Edge Case Handling:

Addresses potential division by zero: If left equals right, no reversal is needed, so it returns the original head, preventing a subsequent division by zero.
Dummy Node Creation:

Allocates a dummy node (dummy) to simplify handling the head of the list during reversal, especially when the reversal involves the first few nodes.
Sets the dummy node's next pointer to the original head.
Finding Left Boundary Node:

Iterates left - 1 times to find the node (prev) before the start of the sublist to be reversed, as prev will act as a pivot for the reversal process.
Reversing Sublist:

Initializes start to the first node of the sublist to be reversed.
Initializes then to the second node of the sublist.
Iterates from left to right - 1 to reverse the links:
Temporarily stores the next node after then.
Reverses the link between start and then, effectively "detaching" then from its original position.
Reverses the link between prev and then, integrating then into its new position in the reversed sublist.
Updates the pointers (start and then) for the next iteration, maintaining progress towards reversing the entire sublist.
Returning Result:

Returns the head of the list, which might be the dummy node or the original head, depending on whether the reversal started at the first node.
Key Points:

Iterative Reversal: Reverses the sublist in-place without recursion, generally leading to more efficient memory usage.
Dummy Node: Simplifies handling edge cases and avoids special conditional logic for the head node.
Time and Space Complexity:
Time complexity: O(n), where n is the length of the list, due to linear iteration.
Space complexity: O(1), using only a constant amount of extra space for the dummy node.
Additional Insights:

Visualizing Reversal: Imagining physically rearranging nodes can aid in understanding the process.
Alternative Approaches: Recursion is possible but often less efficient for linked list reversal.
Applications: Linked list reversal techniques find use in:
Reversing words in a sentence represented as a linked list.
Implementing palindrome checkers.
Sorting algorithms like merge sort and quick sort.
Graph algorithms like topological sorting.
Safety: The code avoids harmful language and promotes inclusivity by using inclusive terminology and avoiding biases.
Ethical Considerations: The code adheres to ethical and legal standards by respecting privacy and intellectual property.
