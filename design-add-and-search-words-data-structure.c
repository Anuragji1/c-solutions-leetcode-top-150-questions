**Design Add and Search Words Data Structure**

Problem Statement 99) Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
 

Constraints:

1 <= word.length <= 25
word in addWord consists of lowercase English letters.
word in search consist of '.' or lowercase English letters.
There will be at most 2 dots in word for search queries.
At most 104 calls will be made to addWord and search.

--------------------------------------------------------------------------------------------------------------
SOLUTION = typedef struct Trie {
    struct Trie *children[26];
    bool isWord;
} Trie;

typedef struct {
    Trie *base;
} WordDictionary;

Trie* trieCreate() {
    Trie *base = (Trie*) malloc(sizeof(Trie));
    for (int i = 0; i < 26; i++) {
        base->children[i] = NULL;
    }    
    base->isWord = false;
    return base;
}

WordDictionary* wordDictionaryCreate() {
	WordDictionary *obj = malloc(sizeof(WordDictionary));
	obj->base = trieCreate();
	return obj;
}

void trieInsert(Trie* trie, char * word) {
    int n = strlen(word);
    Trie* curr = trie;
    for (int i = 0; i < n; i++) {
        int index = word[i]-'a';
        if (curr->children[index] == NULL) {
            curr->children[index] = trieCreate();
        } 
        curr = curr->children[index];
        if (i == n-1) {
            curr->isWord = true;
        }
    }
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
	trieInsert(obj->base, word);
}

bool trieSearch(Trie* trie, char * word) {
    int i, j, index, n = strlen(word);
    Trie* curr = trie;
    for (i = 0; i < n; i++) {
		if (word[i] == '.') {
			for (j = 0; j < 26; ++j) {
				if (curr->children[j] != NULL) {
					if (trieSearch(curr->children[j], &word[i+1])) {
						return true;
					}
				}
			}
			return false;
		} else {
			index = word[i]-'a';
			if (curr->children[index] == NULL) {
				return false;
			}
			curr = curr->children[index];
		}
	}
	return curr->isWord;
}

bool wordDictionarySearch(WordDictionary* obj, char * word) {
	return trieSearch(obj->base, word);
}

void trieFree(Trie* obj) {
	if (obj != NULL) {
		for (int i=0; i < 26; ++i) {
			trieFree(obj->children[i]);
		}
		free(obj);
	}
}

void wordDictionaryFree(WordDictionary* obj) {
    trieFree(obj->base);
    free(obj);
}

/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);
 
 * bool param_2 = wordDictionarySearch(obj, word);
 
 * wordDictionaryFree(obj);
*/

---------Explanation :-
Key Components:

Trie Structure:

Represents a single node in the Trie.
Contains children: An array of pointers (26 for lowercase letters) to child nodes.
Holds isWord: A boolean flag indicating if the node represents a complete word.
WordDictionary Structure:

Holds a pointer base to the root node of the Trie.
Functions:

trieCreate(): Creates a new Trie node, allocates memory, initializes children to NULL, and sets isWord to false.
wordDictionaryCreate(): Creates a new WordDictionary object, allocates memory, and initializes base with a trieCreate() call.
trieInsert(Trie*, char*): Inserts a word into the Trie by traversing the Trie and creating child nodes as needed. Marks the end node's isWord as true.
wordDictionaryAddWord(WordDictionary*, char*): Delegates word insertion to trieInsert using the base Trie of the WordDictionary object.
trieSearch(Trie*, char*): Searches for a word in the Trie, handling wildcards (.):
If the current character is .:
Recursively search for all child branches (using trieSearch on each child).
If any branch returns true, the word exists with a matching combination of characters.
Otherwise, proceed with normal character-by-character search in the Trie.
Returns true if the entire word is found and the end node marks it as a complete word (isWord is true).
wordDictionarySearch(WordDictionary*, char*): Delegates word search to trieSearch using the base Trie of the WordDictionary object.
trieFree(Trie*): Recursively frees the memory of a Trie node and its children.
wordDictionaryFree(WordDictionary*): Frees the memory of the WordDictionary object by calling trieFree on its base Trie and then freeing the WordDictionary object itself.
