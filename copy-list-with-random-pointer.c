**Copy List with Random Pointer**

Problem Statement 61) A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.

------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

// Remark:

// The task of this problem is "deep copy". To understand what "deep copy"
// means, a good method is comparison, i.e., to think of what's a 
// "shallow copy" first, then observe the difference between it and
// the requirement of "deep copy"

// The term, "shallow copy", in this context just mean the most primitive
// and unsophilsicated copy method, i.e., to create a new list which
// shares the same length with the original one, and copy all involved 
// values, namely val and random, node by node.

// To make the new list to be "linked" we mustn't copy the next value
// but make them point to the next node in the new list.

// At this stage, everything perfectly meets the requirement but the 
// "random pointers",which still point to the nodes in the original list

// Then, we must reason out the gap between the current stage and the
// final one. It's not diffcult to perceive that although the random
// pointers in our current copied list are not pointing to the correct
// positions in the copied list. But they do point to the correct
// positions in the original list. Say, for a random pointer which should
// point to the third node in the copied list now is pointing to the 
// third node in the original list. What makes the situation better
// is that the pointers which are supposed be "NULL" are already "NULL".

// So, the objective at this stage is crystal clear: to establish a 
// connection between the corresponding nodes in both lists. It's not
// difficult to find out that the only means is pointer

// Since we are dealing with the issue caused by the random pointers,
// it will make perfect sense should we make use of the random pointers
// themselves to address this problem.

// As we've mentioned before, the address value itself held by a random
// pointer in the original list is of no importance whatsoever but the
// relative position of the node it points to. Since it has already been
// copied to the new list, what we can do is, upon creating a new node
// and copying the address value held by the random pointer in the old
// node into the new node, we can now make the old random value point to
// the new-born node. For example, when we have created the first node
// of the new list and already copied everything we need, we can now
// make random pointer of first node of the original list point to
// the first node of the new list. Through doing so, we

// 1. establish a connection between the correspoding nodes in both lists
// which is the key to our problem

// 2. do not violate the integerity of any information needful of copying

// Now, we just need to tranverse the new list and perform but one 
// operation: node->random = node->random->random if (node->random)
// node->random is the corresponding node in the original list of
// the node in the new list whose address value node->random is supposed
// to hold
// By the mentioned technique, node->random->random stores the address
// value of the correspoding and correct node in the new list.
// So, now, all random pointers in the new list have been correctly set.

struct Node* copyRandomList(struct Node* head) {
  if(!head)
    return head;
  struct Node* p0 = NULL;
  struct Node* p1 = NULL;
  struct Node* newHead = (struct Node*) malloc(sizeof(struct Node));
  newHead->val = head->val;
  newHead->next = NULL;
  newHead->random = head->random;
  head->random = newHead;
  struct Node* p2 = newHead;
  for(p0 = head->next;p0;p0 = p0->next){
    p1 = (struct Node*) malloc(sizeof(struct Node));
    p1->val = p0->val;
    p1->next = NULL;
    p1->random = p0->random;
    p2->next = p1;
    p2 = p1;
    p0->random = p1;
  }
  for(p1 = newHead;p1;p1 = p1->next)
    if(p1->random)
      p1->random = p1->random->random;
  return newHead;
}

-------------------------Explanation :-
Purpose:

This code creates a deep copy of a linked list with random pointers, meaning it creates a completely independent copy of the list with its own nodes and pointers.
Function Breakdown:

Handles Empty List:

Returns NULL if the input list is empty.
Creates Head Node:

Allocates memory for a new head node (newHead).
Copies the val and random pointers from the original head node to the new head node.
Updates the original head node's random pointer to point to the new head node, creating a temporary link for later use.
Iterates and Creates Nodes:

Iterates through the original list, starting from the second node:
Allocates memory for a new node (p1).
Copies the val and random pointers from the current original node to the new node.
Appends the new node to the copied list.
Updates the original node's random pointer to point to the corresponding new node, continuing the temporary links.
Fixes Random Pointers:

Iterates through the copied list:
If the current node's random pointer is not NULL, it sets it to point to the corresponding node in the copied list using the temporary links.
Returns Copied List:

Returns the head of the newly created copied list.
Key Points:

Deep Copy: Ensures complete independence of the copied list.
Random Pointer Handling: Uses a clever technique to establish temporary links between corresponding nodes in both lists, allowing correct copying of random pointers.
Time and Space Complexity: O(n) time complexity and O(1) space complexity, making it efficient for large lists.
