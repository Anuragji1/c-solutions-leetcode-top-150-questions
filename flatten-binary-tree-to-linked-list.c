**Flatten Binary Tree to Linked LIst**

Problem Statement 75) Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

-----------------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    if (root == NULL) {
        return;  // Base case: empty tree
    }

    // Recursively flatten left and right subtrees
    flatten(root->left);
    flatten(root->right);

    // Store the right subtree temporarily
    struct TreeNode* rightSubtree = root->right;

    // Move the left subtree to the right
    root->right = root->left;
    root->left = NULL;  // Set left child to NULL

    // Find the end of the new right subtree (formerly left subtree)
    struct TreeNode* current = root;
    while (current->right != NULL) {
        current = current->right;
    }

    // Attach the original right subtree to the end
    current->right = rightSubtree;
}

-----------------Explanation :-
Purpose:

Flattens a binary tree into a linked list in-place, preserving the original node order.
Breakdown:

Base Case:

If root is NULL, there's nothing to flatten, so the function returns.
Recursive Flattening:

Recursively calls flatten on the left and right subtrees to flatten them individually.
Temporary Storage:

Stores the root->right subtree in a temporary variable rightSubtree for later reattachment.
Right Attachment:

Moves the root->left subtree to the right:
Sets root->right to root->left.
Sets root->left to NULL to make it a singly linked list.
Finding End of New Right Subtree:

Iterates through the newly attached right subtree (which was previously the left subtree) to find its end node.
Reattaching Original Right Subtree:

Connects the original rightSubtree (stored temporarily) to the end of the now flattened right subtree, completing the flattening process.
Key Points:

Recursive Approach: The function employs recursion to flatten subtrees and then combines them at the root.
In-Place Modification: It modifies the tree structure in-place, not creating a new list.
Preserving Node Order: The original node order from the binary tree is maintained in the flattened linked list.
Time and Space Complexity:
Time Complexity: O(n), where n is the number of nodes, as each node is visited once.
Space Complexity: O(h), where h is the height of the tree, due to the recursion stack.
