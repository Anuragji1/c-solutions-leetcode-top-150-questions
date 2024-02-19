**Clone Graph**

Problem Statement 91) Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.
 

Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given node.

--------------------------------------------------------------------------------------------
SOLUTION = struct Node* process(struct Node *s, bool* hash, struct Node** data) { 
    if(hash[s->val] == true)
        return data[s->val];
    struct Node * root = malloc(sizeof(struct Node ));
    root->val = s->val;
    hash[s->val] = true;
    data[s->val] = root;
    root->numNeighbors = s->numNeighbors;
    root->neighbors = malloc(s->numNeighbors * sizeof(struct Node *));
    
    for(int i = 0; i < s->numNeighbors; i++){
        root->neighbors[i] = process( s->neighbors[i], hash, data ); 
    }
    
    return root;
}

struct Node *cloneGraph(struct Node *s) { 
    if(s == NULL)
        return NULL;
    bool* hash = calloc(101 , sizeof(int));
    struct Node** data = malloc(101 * sizeof(struct Node *));
    
    return process(s, hash, data);
}

-----------Explanation :-
Functionality:

This code implements a function cloneGraph that creates a deep copy (clone) of a given graph represented by a node structure containing val (node value) and neighbors (a list of neighboring nodes). It employs a recursive approach and a hash table to avoid duplicate node creation.

Key Steps:

Base Case:

If the input s is NULL, return NULL as an empty graph.
Initialization:

Create a hash table hash (boolean array) with a size of 101 (arbitrary choice) to keep track of visited nodes.
Create a data array data with a size of 101 to store cloned nodes, indexed by their original node values.
Recursive process Function:

Check for Visited Node:
If hash[s->val] is true, it means the node with value s->val has already been visited and cloned, so return the corresponding cloned node from data[s->val].
Create New Node:
Allocate memory for a new node root using malloc and copy the val from the original node.
Set hash[s->val] to true to mark the node as visited.
Store the new node in data[s->val] for mapping the original node to its clone.
Copy the numNeighbors from the original node to the cloned node.
Allocate memory for the neighbors array in the cloned node using malloc.
Recursively Clone Neighbors:
Iterate through the original node's neighbors array:
For each neighbor s->neighbors[i]:
Recursively call process to clone the neighbor and obtain its cloned version.
Store the cloned neighbor in the corresponding index of the neighbors array in the current cloned node (root->neighbors[i]).
Return Cloned Node:
Return the cloned node root after processing all its neighbors.
Return Result:

The cloneGraph function returns the result of calling process on the input s, which is the root node of the cloned graph.
Key Points:

The code effectively clones the graph using recursion and a hash table to avoid redundant node creation.
The data array maps original node values to their corresponding cloned nodes for efficiency.
The time complexity is O(n + m), where n is the number of nodes and m is the number of edges, due to visiting each node once and exploring its neighbors.
The space complexity is O(n + m) due to the recursion stack, hash table, and cloned graph creation.
Example:

Consider a graph with nodes (A, B, C) and edges (A->B, B->C, C->A):

A -> B -> C
|   ^
|   |
|___/
The cloned graph would be:

A' -> B' -> C'
|   ^
|   |
|___/
