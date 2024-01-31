**Add Two Numbers**

Problem Statement 59) You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

--------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    struct ListNode* head = (struct ListNode*) malloc (sizeof(struct ListNode));
    bool flag = true;
    head->val = 0;
    head->next = NULL;
    struct ListNode* iter = head;
    int num1 = 0;
    int num2 = 0;
    int sum = 0;
    int carry = 0;
    while (l1 || l2 || carry) {
        if(l1) {
            num1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            num2 = l2->val;
            l2 = l2->next;
        }
        sum = num1+num2 + carry;
        if (carry)
            carry = 0;
        if (sum > 9) {
            carry = 1;
            sum = sum%10;
        }
        if (flag) {
            flag = false;
            iter->val = sum;
        } else {
            struct ListNode* node = (struct ListNode*) malloc (sizeof(struct ListNode));
            node->next = NULL;
            iter->next = node;
            node->val = sum;
            iter = iter->next;
        }
        
        num1 = 0;
        num2 = 0;
    }
    
    return head;
}

-----------------------Code Explanation :- 
Purpose:

This code adds two non-negative integers represented as linked lists, where each digit is a node in reverse order (e.g., 9->2->3 represents 329).
It returns a new linked list representing the sum.
Function Breakdown:

Initialization:

Creates a new list head with a dummy head node (value 0).
Initializes pointers (iter, l1, l2), variables (flag, num1, num2, sum, carry).
Iterating and Adding Digits:

Iterates as long as either l1, l2, or carry is not 0:
Gets digits from l1 and l2 if they exist.
Calculates sum by adding digits and carry.
Handles carry-over for sums greater than 9.
If it's the first iteration, updates the dummy head's value.
Otherwise, creates a new node, appends it to the list, and updates iter.
Resets num1 and num2 for the next iteration.
Returning Result:

Returns the head of the newly created list representing the sum.
Key Points:

Linked List Arithmetic: Demonstrates how linked lists can represent numbers and perform arithmetic operations.
Reverse Order: Uses the reverse order to simplify addition without reversing the lists beforehand.
Carry-Over Handling: Manages carry-over between digits using the carry variable.
Memory Allocation: Uses malloc to allocate memory for new nodes.
Time and Space Complexity: O(max(m, n)) time complexity, where m and n are the lengths of the lists. O(max(m, n)) space complexity for the result list.
