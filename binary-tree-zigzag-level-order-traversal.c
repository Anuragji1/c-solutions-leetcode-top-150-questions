**Binary Tree Zigzag Level Order Traversal**

Problem Statement 85) Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

-----------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int** result = (int**)malloc(sizeof(int*) * 2000);  // Allocate space for levels
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);  // Allocate space for level sizes

    int level = 0;
    struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 2000);
    int front = 0, rear = 0;
    queue[rear++] = root;

    int leftToRight = 1;  // Flag for traversal direction

    while (front < rear) {
        int size = rear - front;
        result[level] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; ++i) {
            struct TreeNode* node = queue[front++];
            int index = leftToRight ? i : size - 1 - i;  // Determine index based on direction
            result[level][index] = node->val;

            if (node->left) {
                queue[rear++] = node->left;
            }
            if (node->right) {
                queue[rear++] = node->right;
            }
        }

        leftToRight = !leftToRight;  // Toggle direction for next level
        level++;
    }

    *returnSize = level;
    free(queue);
    return result;
}

------------------Explanation :-
Functionality:

This function performs a zigzag level-order traversal of a binary tree, returning a 2D array where each sub-array contains the node values at a specific level, following a left-to-right or right-to-left pattern alternately for each level.

Code Breakdown:

Base Case:

If root is NULL, an empty tree exists, so:
Set *returnSize to 0 (no levels).
Set *returnColumnSizes to NULL (no size array).
Return NULL (no result array).
Initialization:

Allocate memory for the 2D result array using malloc with a maximum size of 2000 levels.
Allocate memory for the column size array using malloc with a maximum size of 2000 levels.
Create a queue using a dynamically allocated array of TreeNode* pointers to store nodes during traversal.
Initially, set front = 0 (no elements dequeued) and rear = 0 (no elements enqueued).
Add the root node to the queue (queue[rear++] = root).
Create a leftToRight flag initially set to 1 (left-to-right traversal for the first level).
BFS Loop with Zigzag Traversal:

Enter a while loop that continues as long as there are nodes in the queue (front < rear).
Get the current level size (size = rear - front).
Allocate memory for the current level's array in the result (result[level]).
Set the corresponding column size in *returnColumnSizes.
Iterate through nodes at the current level (for loop):
Dequeue the front node (struct TreeNode* node = queue[front++]).
Calculate the index in the current level's array based on the leftToRight flag:
If leftToRight is true, use the current index i.
Otherwise, use the reversed index size - 1 - i.
Store the node's value at the calculated index in the result array (result[level][index]).
Enqueue the node's children to the queue:
Add the left child if it exists (queue[rear++] = node->left).
Add the right child if it exists (queue[rear++] = node->right).
Toggle the leftToRight flag for the next level's traversal direction.
Increment the level counter to track the current level.
Return Values:

Set *returnSize to the final level number.
Free the memory used by the queue (free(queue)).
Return the result array (result).
Key Points:

Leverages breadth-first search (BFS) to efficiently explore the tree level-by-level.
Uses a queue to manage node exploration and maintain level information.
Employs a flag to alternate between left-to-right and right-to-left traversal at each level.
Dynamically allocates memory for the result and column size arrays.
Manages memory by freeing the queue after use.
Time and Space Complexity:

Time complexity: O(n), where n is the number of nodes (visits each node once).
Space complexity: O(n), due to the queue, result array, and column size array.
