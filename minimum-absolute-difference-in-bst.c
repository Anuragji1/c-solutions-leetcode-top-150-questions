**Minimum Absolute Difference in BST**

Problem Statement 86) Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:


Input: root = [4,2,6,1,3]
Output: 1
Example 2:


Input: root = [1,0,48,null,null,12,49]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 104].
0 <= Node.val <= 105


--------------------------------------------------------------------------------------
SOLUTION - /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getMinimumDifference(struct TreeNode* root) {
    int minDiff = INT_MAX;
    int prev = -1;  // Hold value of previous node

    // In-order traversal to ensure nodes are visited in ascending order
    void inorder(struct TreeNode* node) {
        if (node == NULL) return;

        inorder(node->left);

        if (prev != -1) {
            minDiff = fmin(minDiff, node->val - prev);
        }
        prev = node->val;

        inorder(node->right);
    }

    inorder(root);
    return minDiff;
}

-----------Explanation :-
This code implements a function getMinimumDifference that takes a binary tree root as input and returns the minimum difference in value between any two nodes in the tree. Here's how it works:

In-Order Traversal:

Base Case:

If node is NULL, it means we've reached the end of a branch, so there's no difference to calculate here.
Recursive Calls:

The function makes two recursive calls:
inorder(node->left): Traverses the left subtree in-order.
inorder(node->right): Traverses the right subtree in-order.
Calculating Minimum Difference:

After visiting the left subtree:
If prev (previous node value) is not -1 (meaning we're not on the first node), it implies we have two nodes to compare.
Calculate the difference between the current node's value (node->val) and prev.
Compare this difference with the current minDiff and update minDiff if it's smaller.
Update prev to the current node's value (prev = node->val) for the next comparison in the right subtree.
Key Points:

In-order traversal ensures nodes are visited in ascending order based on their values.
By comparing the current node's value with the previous node's value, we get the difference between two consecutive nodes.
The minimum of these differences throughout the traversal is the minimum difference in the entire tree.
The time complexity is O(n) due to visiting each node once in the in-order traversal.
The space complexity is O(h) due to the recursion stack, where h is the tree's height.
