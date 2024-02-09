**Construct Binary Tree From Inorder and Postorder Traversal**

Problem Statement 74) Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
 

Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

----------------------------------------------------------------------------------
Solution = /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (postorderSize == 0) {
        return NULL;  // Base case: empty tree
    }

    // Root is the last element in postorder
    int rootValue = postorder[postorderSize - 1];
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootValue;

    // Find the root's index in inorder
    int rootIndex = 0;
    while (inorder[rootIndex] != rootValue) {
        rootIndex++;
    }

    // Recursively construct right and left subtrees (note the order!)
    root->right = buildTree(inorder + rootIndex + 1, inorderSize - rootIndex - 1, postorder + rootIndex, postorderSize - rootIndex - 1);
    root->left = buildTree(inorder, rootIndex, postorder, rootIndex);

    return root;
}

------------------Explanation:-
This code defines a function buildTree that takes the inorder and postorder traversals of a binary tree and constructs the corresponding tree. Here's a breakdown of the code and how it works:

Base Case:

If the postorderSize is 0, it means there are no nodes to build, so the function returns NULL.
Root Construction:

The root node is identified as the last element in the postorder array (postorder[postorderSize - 1]).
A new TreeNode is created and assigned the root value.
Finding Root Index in Inorder:

Similar to the previous explanation, the function iterates through the inorder array to find the index of the root value. This index determines the split between the left and right subtrees in the inorder traversal.
Recursive Subtree Construction:

However, here's the key difference:
The right subtree is constructed first:
Using inorder + rootIndex + 1 and inorderSize - rootIndex - 1, we grab the right subtree portion of the inorder array.
Using postorder + rootIndex and postorderSize - rootIndex - 1, we grab the right subtree portion of the postorder array.
This is because in postorder, the right subtree comes before the left subtree.
Then, the left subtree is constructed:
Using inorder and rootIndex, we grab the entire left subtree portion of the inorder array.
Using postorder and rootIndex, we grab the nodes for the left subtree from the postorder array (up to the root).
Return Value:

The function returns the constructed TreeNode representing the root of the built binary tree.
Key Points:

This approach relies on the unique properties of postorder traversal, where the root follows its right and left subtrees.
The time complexity remains O(n) due to linear traversals and recursive calls.
The space complexity is also O(h) due to the recursion stack.
