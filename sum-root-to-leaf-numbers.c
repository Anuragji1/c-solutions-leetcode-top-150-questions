**Sum Root to Leaf Numbers**

Problem Statement 77) You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.

 

Example 1:


Input: root = [1,2,3]
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:


Input: root = [4,9,0,5,1]
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 9
The depth of the tree will not exceed 10.

-----------------------------------------------------------------------------------------
SOLUTION - /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int calNum(struct TreeNode*root,int treeNumber){
    if(root==NULL)
        return 0;  
    
    if(root->left==NULL && root->right==NULL)
        return treeNumber*10+root->val;
    else
        return calNum(root->left,treeNumber*10+root->val)+calNum(root->right,treeNumber*10+root->val);

}


int sumNumbers(struct TreeNode* root){
int result =calNum(root,0);
    return result;
    
}

------Explanation :-
calNum function:

Takes two arguments:
root: Pointer to the current node in the tree.
treeNumber: An integer representing the partial path value constructed so far (initially 0).
Base case:
If root is NULL, it means the end of a path is reached. In this case, the function returns 0, as there's no value to contribute to the path sum.
Leaf node check:
If root->left and root->right are both NULL, it means a leaf node is encountered.
The function returns treeNumber * 10 + root->val. This:
Multiplies the current treeNumber by 10 to shift the existing digits one place to the left.
Adds the value of the current leaf node (root->val) to the end of the path number.
Recursive calls:
Otherwise, the function makes two recursive calls:
calNum(root->left, treeNumber * 10 + root->val): Processes the left subtree by appending the current node's value and moving to the left child.
calNum(root->right, treeNumber * 10 + root->val): Processes the right subtree similarly.
Return value:
The function returns the sum of the results from the left and right subtree recursive calls. This effectively adds the path values from both subtrees to the current path.
2. sumNumbers function:

Takes a single argument: root, the pointer to the root node of the tree.
Calls the calNum function with root and 0 (initial empty path value).
Returns the result from calNum, which is the sum of all root-to-leaf path values calculated as numbers.
Key points:

The code recursively explores all possible paths from the root to leaf nodes.
At each node, the current path value is built by concatenating the node's value to the existing prefix (treeNumber).
The sum of all these path values (represented as numbers) is returned by the sumNumbers function.
Time and space complexity:

Time complexity: O(n), where n is the number of nodes in the tree, as each node is visited once in the worst case.
Space complexity: O(h), where h is the height of the tree, due to the recursion stack.
