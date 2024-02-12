**Count Complete Tree Nodes**

Problem Statement 80) Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.

-------------------------------------------------------------------------
SOLUTION - /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = 0, rightHeight = 0;
    struct TreeNode *left = root, *right = root;

    // Get heights of left and right subtrees
    while (left != NULL) {
        left = left->left;
        leftHeight++;
    }
    while (right != NULL) {
        right = right->right;
        rightHeight++;
    }

    // If heights are equal, it's a full tree: 2^height - 1
    if (leftHeight == rightHeight) {
        return (1 << leftHeight) - 1;
    }

    // Otherwise, count nodes recursively in subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);
}

----------------Explanation :-

This code defines the countNodes function that efficiently counts the number of nodes in a binary tree. Here's a breakdown of its logic:

Base Case:

If root is NULL, it's an empty tree with no nodes, so the function returns 0.
Checking for a Perfect Binary Tree:

It calculates the heights of the left and right subtrees by iterating down each side until a NULL node is encountered.
If both heights are equal (leftHeight == rightHeight), it signifies a perfect binary tree, where all levels are completely filled except possibly the last rightmost level.
For perfect binary trees, the number of nodes can be calculated directly using the formula 2^height - 1, where height is the common left and right subtree height. The function returns this value if it detects a perfect binary tree.
Recursive Counting for Non-Perfect Trees:

If the tree is not perfect (heights differ), it's not possible to compute the node count directly.
The function recursively calls itself for both the root->left and root->right subtrees to count the number of nodes in each subtree.
Finally, it adds 1 to the root node itself and the counts from both subtrees to get the total node count for the entire tree.
Key Points:

This function utilizes two approaches: direct calculation for perfect binary trees and recursive counting for other trees.
It avoids unnecessary traversals by checking for perfect binary trees first.
The time complexity is O(h) for perfect binary trees due to constant-time height calculation and direct formula application. For non-perfect trees, it's O(n), where n is the number of nodes, due to recursive calls.
The space complexity is O(h) due to the recursion stack for both perfect and non-perfect trees.
