**Construct Binary Tree from Preorder and Inorder Traversal**

Problem Statement 73) Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

------------------------------------------------------------------------------
SOLUTION = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 0) {
        return NULL;  // Base case: empty tree
    }

    // Root is the first element in preorder
    int rootValue = preorder[0];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootValue;

    // Find the root's index in inorder
    int rootIndex = 0;
    while (inorder[rootIndex] != rootValue) {
        rootIndex++;
    }

    // Recursively construct left and right subtrees
    root->left = buildTree(preorder + 1, rootIndex, inorder, rootIndex);
    root->right = buildTree(preorder + rootIndex + 1, preorderSize - rootIndex - 1, inorder + rootIndex + 1, inorderSize - rootIndex - 1);

    return root;
}

---------------------Explanation :-
Explanation of buildTree function:
The provided code defines a function buildTree that takes two integer arrays representing the preorder and inorder traversals of a binary tree and constructs the corresponding binary tree. Here's a breakdown of the code and its logic:

Base Case:

If the input preorderSize is 0, it means there are no nodes to build, so the function returns NULL.
Root Construction:

The root node is identified as the first element in the preorder array (preorder[0]).
A new TreeNode is created and assigned the root value.
Finding Root Index in Inorder:

The function iterates through the inorder array to find the index of the root value. This index divides the inorder traversal into two parts: left and right subtrees.
Recursive Subtree Construction:

The buildTree function is called recursively for the following subarrays:
preorder from index 1 to rootIndex: Represents the left subtree.
inorder from 0 to rootIndex: Represents the left subtree.
preorder from rootIndex + 1 to the end: Represents the right subtree.
inorder from rootIndex + 1 to the end: Represents the right subtree.
The returned subtrees are assigned to the left and right pointers of the root node.
Return Value:

The function returns the constructed TreeNode representing the root of the built binary tree.
Key Points:

The function relies on the properties of preorder and inorder traversals to uniquely identify the root and its subtrees.
The time complexity of this approach is O(n), where n is the number of nodes in the tree, due to the linear traversals and recursive calls.
The space complexity is O(h), where h is the height of the tree, due to the recursion stack.
