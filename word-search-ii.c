**Word Search ii**

Problem Statement 100) Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.

----------------------------------------------------------------------
Solution = /**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** result;
int pos;
char** B;
int M, N;
char** W;
int K;

bool seen[30000];
bool visited[13][13];

typedef struct
{
    bool is_leaf;
    int index;
    void* next[26];
} Trie;

char stack[12];
int tos;

void push (char c)
{
    stack[tos] = c;
    tos++;
}
void pop (void)
{
    tos--;
}

Trie* create_node (void)
{
    Trie* obj = (Trie*) malloc (sizeof(Trie));
    memset (obj->next, 0, 26 * sizeof(Trie*));
    obj->is_leaf = 0;
    obj->index = -1;
    return obj;
}

void insert_word (Trie* T, int i)
{
    char* str = W[i];
    char c;
    int level = 0;
    int len = strlen(str);

    while (1)
    {
        c = str[level] - 'a';

        if (T->next[c] == NULL)
            T->next[c] = (void*)create_node ();
        level++;
        if (level >= len)
        {
            ((Trie*)T->next[c])->is_leaf = 1;
            ((Trie*)T->next[c])->index = i;
            break;
        }
        T = ((Trie*)T->next[c]);
    }
}


Trie* create_trie(void)
{
    Trie* T = create_node();

    for (int i = 0; i < K; i++)
        insert_word (T, i);

    return (T);
}

void dfs (int i, int j, Trie* node)
{
    // base condtion
    if (i < 0 || j < 0 || i >= M || j >= N || visited[i][j] || tos > 10)
        return;
    char c = B[i][j];
    visited[i][j] = 1;
    push (c);
    // Check if current char exists in TRIE.
    node = node->next[c - 'a'];

    if (node)
    {
        //printf ("-->%d, %d %c\n", i, j, c);
        // Check if end of word is reached.
        if (node->is_leaf && seen[node->index] == 0)
        {
            // Save word in result.
                // malloc space for result.
                // insert \0            
            push ('\0');
            result[pos] = (char*) malloc (sizeof(char) * (tos));
            memcpy (result[pos], stack, tos);
            //printf ("Saved %s node index = %d seen = %d\n", stack, node->index, seen[node->index]);
            seen[node->index] = 1;
            pos++;
            pop ();
        }
        // 4 ways DFS
        dfs (i-1, j, node);
        dfs (i+1, j, node);
        dfs (i, j-1, node);
        dfs (i, j+1, node);
        //printf ("<--%d, %d\n", i, j);
    }
    visited[i][j] = 0;
    pop ();
}



char ** findWords(char** board, int boardSize, int* boardColSize, char ** words, int wordsSize, int* returnSize)
{
    /*
    Algo: 
    0. Create a Trie for the given words.
    1. Loop over all cells of the matrix until last letter is reached or all words have been consumed (maintain an array of boolean "seen" against words):
        a. For each cell, do DFS in four direction: N, E, S & W.
        b. Query and get a pointer to the trie object for the character in new cell of the board.
        c. If trie node pointer is null, and end of word is not reached and return to caller. 
        d. maintain visited[], and clear it when returning from DFS.
        e. If trie node is not null and end of word W is reached, then save the word in result, mark this word as seen and return to caller.
    */

    B = board;
    M = boardSize;
    N = *boardColSize;
    W = words;
    K = wordsSize;
    tos = 0;
    pos = 0;

    result = (char**) malloc (sizeof(char*) * wordsSize);
    memset (seen, 0, sizeof(bool) * K);

    for (int i =0; i < M; i++)
        memset (visited[i], 0, sizeof(bool) * N);

    Trie* T = create_trie ();

    for (int i = 0; i < boardSize; i++)
        for (int j = 0; j < *boardColSize; j++)
        {
            //printf ("Starting DFS at %d %d\n", i,j);
            dfs (i, j, T);

        }
    *returnSize = pos;
    return result;
}

------------Explanation :-
Trie:
Created using the provided create_trie function, efficiently storing the given words for quick checks.
Board:
Represented by a 2D array board of characters.
M and N store the number of rows and columns in the board, respectively.
Words:
Represented by a 2D array words of strings.
K stores the number of words to search for.
Search Process:
DFS:
Iterates through each cell in the board (i, j).
For each cell, calls dfs to explore possible word combinations:
Base cases: Check if out of bounds, already visited, or stack exceeds a limit.
Push the current character onto a stack (stack).
Look up the corresponding node in the Trie for the current character.
If the node is not found or the end of word is not reached, backtrack.
If the node is found and marks the end of a word (is_leaf):
Check if the word has not been found before (seen[node->index] == 0).
If the word is new:
Allocate memory for a new string to store the word.
Copy the characters from the stack to the newly allocated string.
Add the word to the result array.
Mark the word as seen (seen[node->index] = 1).
Recursively call dfs for neighbors (up, down, left, right) of the current cell.
After exploring neighbors, pop the current character from the stack and mark the cell as unvisited.
Result:
The findWords function returns the result array containing all found words and updates the returnSize variable with the number of words found.
