**Linked List Cycle**

Problem Statement 58) Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

---------------------------------------------------------------------------------------------------------------------
SOLUTION = bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;  // Empty or single-node list has no cycle
    }

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle found
}


---------------Explanation :-
Function Breakdown:

Handles Empty/Single-Node Lists:

Returns false if the list is empty or has only one node, as cycles are impossible in these cases.
Initializes Two Pointers:

Creates pointers slow and fast, both starting at the head of the list.
Iterates Through the List:

Continues iterating as long as fast and its next node are not NULL:
Moves slow one node forward.
Moves fast two nodes forward.
Checks if slow and fast now point to the same node:
If so, a cycle is detected, and the function returns true.
Returns false If No Cycle:

If the loop finishes without finding a cycle, the function returns false.
Key Points:

Floyd's Cycle-Finding Algorithm: Employs a classic technique using two pointers moving at different speeds to detect cycles efficiently.
Time and Space Complexity: O(n) time complexity and O(1) space complexity, making it efficient for large lists.
