**Lowest Common Ancestor of a Binary Tree**

Problem Statement 81) Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.

-----------------------------------------------------------------------
SOLUTION - /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root; // Base cases: If root is NULL, p, or q, it's the LCA
    }

    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left == NULL) {
        return right; // If p and q are both in the right subtree
    } else if (right == NULL) {
        return left; // If p and q are both in the left subtree
    } else {
        return root; // If p and q are in different subtrees, root is the LCA
    }
}

---------------Explanation :-
This code implements a function lowestCommonAncestor that takes a binary tree root and two nodes p and q as input and returns the lowest common ancestor (LCA) of these two nodes in the tree. Here's how it works:

Recursive Approach:

Base Cases:

If root is NULL, p, or q, it means either the tree is empty or one of the target nodes is found as the root itself. In these cases, the current root node is returned as the LCA.
Recursive Calls:

The function makes two recursive calls:
left = lowestCommonAncestor(root->left, p, q): Searches for the LCA in the left subtree.
right = lowestCommonAncestor(root->right, p, q): Searches for the LCA in the right subtree.
Identifying LCA:

If both left and right are NULL, it means neither p nor q is found in the current subtree. Therefore, the LCA can't be in this subtree, so the function returns right.
Conversely, if both left and right are not NULL, it means both p and q are found in different subtrees of the current root node. In this case, the current root itself becomes the LCA as it's the closest common ancestor to both nodes.
If only one of left or right is NULL, it implies one of the nodes is found in that subtree while the other is not. So, the LCA for these specific p and q must be in the non-NULL subtree, and the corresponding left or right value is returned.
Key Points:

This recursive approach works by examining the presence of p and q in different subtrees of the root node.
It uses the property that the LCA of two nodes must lie on the path between them in the tree.
The time complexity is O(n) in the worst case, where n is the number of nodes, as each node might be visited once.
The space complexity is O(h) due to the recursion stack, where h is the tree's height.
