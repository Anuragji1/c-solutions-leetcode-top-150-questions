**Binary Tree Right Side View**

Problem Statement 82) Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

------------------------------------------------------------------------------
SOLUTIOn = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int *result = (int*)malloc(sizeof(int) * 100);  // Assuming max 100 nodes
    *returnSize = 0;

    struct TreeNode **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;  // Nodes at current level
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode *node = queue[front++];
            if (i == levelSize - 1) {  // Last node at this level
                result[*returnSize] = node->val;
                (*returnSize)++;
            }
            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }
    }

    free(queue);
    return result;
}

---------Explanation :-
This code implements the rightSideView function to find and return the rightmost node values seen from each level of a binary tree in a right-to-left order. Here's a breakdown of the code:

Base Case:

If the root is NULL, there's no tree, so it returns an empty array (*returnSize = 0) and NULL.
Initialization:

Allocates memory for the result array (result) to hold the rightmost node values (initially assuming 100 nodes).
Sets the returnSize to 0 as no elements have been added yet.
Creates a queue (queue) of pointers to TreeNodes to implement breadth-first search (BFS).
Adds the root node to the queue and increments the rear pointer.
Level-Order Traversal:

Uses a while loop to process levels of the tree iteratively:
Calculates the number of nodes (levelSize) at the current level by subtracting front and rear indices of the queue.
Iterates through all nodes at the current level (for loop):
Dequeues the front node (node) and updates the front pointer.
If i (node index) is equal to levelSize - 1 (last node at the level), it means it's the rightmost node, so its value is added to the result array, and the returnSize is incremented.
Enqueues the node's left child to the queue if it exists.
Enqueues the node's right child to the queue if it exists.
This loop ensures only the rightmost node of each level is captured.
Returning the Result:

Frees the memory allocated for the queue.
Returns the result array containing the rightmost node values in right-to-left order and the actual size (*returnSize) in the provided pointer.
Key Points:

This code employs BFS to traverse the tree level-by-level, making it efficient for capturing rightmost nodes.
It uses a queue to manage node exploration and keep track of current level nodes.
The assumption of a maximum of 100 nodes in the array can be adjusted based on specific requirements.
The time complexity is O(n), where n is the number of nodes, due to visiting each node once.
The space complexity is O(n) due to the queue size, which can hold all nodes in the worst case.
