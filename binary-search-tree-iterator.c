**Binary Search Tree Iterator**

Problem Statement 79) Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.

 

Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.

-------------------------------------------------------------------------------------
SOLUTION - #include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode *stack[10000];
    int top;
} BSTIterator;

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->top = -1;
    pushAllLeft(obj, root);
    return obj;
}

void pushAllLeft(BSTIterator* obj, struct TreeNode* root) {
    while (root != NULL) {
        obj->stack[++obj->top] = root;
        root = root->left;
    }
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->top != -1;
}

int bSTIteratorNext(BSTIterator* obj) {
    struct TreeNode* node = obj->stack[obj->top--];
    pushAllLeft(obj, node->right);
    return node->val;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

----------------Explanation :-
This code defines an implementation for an iterator that traverses a Binary Search Tree (BST) in inorder. Here's a breakdown of the functions:

BSTIterator* bSTIteratorCreate(struct TreeNode* root):

Creates a new BSTIterator object and initializes its top index to -1 (empty stack).
Calls pushAllLeft to push all left nodes from the root down onto the stack, effectively setting up the initial state for inorder traversal.
Returns the created BSTIterator object.
void pushAllLeft(BSTIterator* obj, struct TreeNode* root):

Helper function to push all left child nodes from the given root node onto the stack of the BSTIterator object.
Uses a while loop to iterate down the left subtree, pushing each node onto the stack until a NULL node is encountered.
bool bSTIteratorHasNext(BSTIterator* obj):

Checks if there are more nodes to iterate over by checking if the top index of the stack is not -1 (not empty).
Returns true if there are more nodes and false otherwise.
int bSTIteratorNext(BSTIterator* obj):

Retrieves the next node in the inorder traversal:
Pops the top node from the stack.
Pushes all left children of the popped node's right subtree onto the stack (if any) to prepare for visiting them next.
Returns the value of the popped node.
void bSTIteratorFree(BSTIterator* obj):

Frees the memory allocated for the BSTIterator object.
Key Points:

This iterator uses a stack to keep track of nodes during inorder traversal.
It starts by pushing all left nodes from the root onto the stack, ensuring the leftmost node is visited first.
The hasNext function checks if the stack is empty, indicating the end of the traversal.
The next function pops the top node, pushes its right subtree's left nodes, and returns the popped node's value.
This implementation offers a space-efficient way to perform inorder traversal without recursion.
