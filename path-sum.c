**Path Sum**

Problem Statement 76) Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.
Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

--------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;  // Base case: empty tree
    }

    if (root->left == NULL && root->right == NULL && root->val == targetSum) {
        return true;  // Leaf node with matching value
    }

    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

--------------Explanation :-
Explanation of hasPathSum function:
This code defines a hasPathSum function that takes a binary tree root and a target targetSum and returns true if there exists a path from the root to any leaf node where the sum of node values along the path equals the target sum. Otherwise, it returns false.

Breakdown:

Base Case:

If the root is NULL, meaning an empty tree, return false as there's no path possible.
Leaf Node Check:

If the current node is a leaf (both left and right are NULL), and its value equals the targetSum, it means the path ends here and matches the target, so return true.
Recursive Exploration:

Otherwise, explore both possible paths recursively:
Call hasPathSum on the left child with the remaining target sum (targetSum - root->val), indicating that the current node's value has been added to the path sum.
Call hasPathSum on the right child with the remaining target sum, similar to the left branch.
Return true if either recursive call returns true, meaning a path with the target sum exists in either the left or right subtree. Otherwise, return false, indicating no matching path was found in either branch.
Key Points:

Recursive Design: The function explores potential paths recursively, checking left and right subtrees and updating the remaining target sum.
Leaf Node Match: It specifically checks leaf nodes for reaching the target sum after considering all possible paths.
Time and Space Complexity:
Time Complexity: O(n) in the worst case, visiting each node once. However, it can be faster for balanced trees or early termination due to finding a path sooner.
Space Complexity: O(h) due to the recursion stack, where h is the height of the tree.
