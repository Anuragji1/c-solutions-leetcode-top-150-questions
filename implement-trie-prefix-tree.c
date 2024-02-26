**Implement Trie (Prefix Tree)**

Problem Statement 98) A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
 

Constraints:

1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 104 calls in total will be made to insert, search, and startsWith.

-----------------------------------------------------------------------------------------
SOLUTION = #include <stdbool.h>

typedef struct TrieNode {
    bool isEnd;
    struct TrieNode* children[26]; // Assuming lowercase English letters
} TrieNode;

typedef struct {
    TrieNode* root;
} Trie;

Trie* trieCreate() {
    Trie* obj = malloc(sizeof(Trie));
    obj->root = calloc(1, sizeof(TrieNode));  // Initialize root node
    return obj;
}

void trieInsert(Trie* obj, char* word) {
    TrieNode* current = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = calloc(1, sizeof(TrieNode));
        }
        current = current->children[index];
    }
    current->isEnd = true;
}

bool trieSearch(Trie* obj, char* word) {
    TrieNode* current = obj->root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return current->isEnd;  // Check if it's a complete word
}

bool trieStartsWith(Trie* obj, char* prefix) {
    TrieNode* current = obj->root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (!current->children[index]) {
            return false;
        }
        current = current->children[index];
    }
    return true;  // Prefix exists in the trie
}

void trieFree(Trie* obj) {
    // Recursively free nodes
    freeTrieNode(obj->root);
    free(obj);
}

void freeTrieNode(TrieNode* node) {
    if (node) {
        for (int i = 0; i < 26; i++) {
            freeTrieNode(node->children[i]);
        }
        free(node);
    }
}

----------Explanation :-
 Trie Structure:

TrieNode: Represents a single node in the Trie, containing:

isEnd: Boolean flag indicating whether the node represents a complete word.
children: Array of pointers to child nodes (one for each lowercase letter).
Trie: Represents the entire Trie, containing:

root: Pointer to the root node of the Trie.
2. Functions:

trieCreate(): Creates and initializes a new Trie object, allocating memory for the root node.

trieInsert(Trie*, char*): Inserts a given word into the Trie by traversing the Trie and creating any necessary child nodes. Marks the end node (isEnd) as true to indicate a complete word.

trieSearch(Trie*, char*): Searches for a given word in the Trie. Returns true if the word exists and is a complete word (marked as isEnd in the final node), otherwise false.

trieStartsWith(Trie*, char*): Checks if a given prefix exists in the Trie. Traverses the Trie until the end of the prefix. Returns true if the prefix exists, otherwise false.

trieFree(Trie*): Frees the memory allocated for the entire Trie by recursively calling freeTrieNode on the root node.

freeTrieNode(TrieNode*): Recursively frees the memory of a Trie node and its children.
