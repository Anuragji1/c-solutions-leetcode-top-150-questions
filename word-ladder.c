**Word Ladder**

Problem Solving 97) A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.

------------------------------------------------------------------------------------------------------------------
SOLUTION = int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){

    int len = strlen(beginWord);

    

    //table[i][0] : count

    //table[i][x] : record items that distance is 1 from  wordList[i]

    int** table = malloc(wordListSize * sizeof(int*));

    for(int i = 0; i < wordListSize; i++){

        table[i] = malloc(wordListSize * sizeof(int));

    }

    int last = -1;

    int pos;

    for(int i = 0; i < wordListSize; i++){

        table[i][0] = 0;

    }

    for(int i = 0; i < wordListSize ; i++){

        if(strcmp(endWord, wordList[i]) == 0)

            last = i;

        for(int j = i+1; j < wordListSize; j++){

            int d = 0;

            for(int k = 0; k < len; k++){

                if(wordList[i][k] != wordList[j][k])

                    d++;

                if(d > 1)

                    break;

            }

            if(d == 1){                 

                table[i][0]++;

                pos = table[i][0];   

                table[i][pos] = j; 

                

                table[j][0]++;

                pos = table[j][0];   

                table[j][pos] = i; 

            }

        }

        table[i] = realloc(table[i], (table[i][0]+1)* sizeof(int) );

    }



    int* stack1 = malloc((wordListSize+1) * sizeof(int));

    int* stack2 = malloc((wordListSize+1) * sizeof(int));

    int idx1 = 0, idx2 = 0;

    bool* alreadyAdd = calloc(wordListSize, sizeof(int));

    for(int i = 0; i < wordListSize; i++){

        int d = 0;

        for(int j = 0; j < len; j++){

            if(beginWord[j] != wordList[i][j])

                d++;

            if(d > 1)

                break;

        }

        if(d == 1){

            if(i == last)

                return 2;

            stack1[idx1] = i;

            alreadyAdd[i] = true;

            idx1++;

        }

    }

    if(idx1 == 0)

        return 0;

    int level = 2;

    bool* visit = calloc(wordListSize, sizeof(int));    

    bool flag = true;

    int cn = idx1 ;

    int p;

    while(idx1 > 0 || idx2 > 0){

        if(idx1 > 0){

            for(int i = 0; i < idx1; i++){

                p = stack1[i];

                if(visit[p])

                    continue;

                visit[p] = true;

                for(int j = 1; j <= table[p][0]; j++){

                    int z = table[p][j]; 

                    if(z == last)

                        return level + 1;

                    if(visit[z] == false && alreadyAdd[z] == false){

                        stack2[idx2] = z;

                        alreadyAdd[z] = true;  

                        idx2++;

                    }

                }

            }

            idx1 = 0;            

        }

        else{

            for(int i = 0; i < idx2; i++){

                p = stack2[i];

                if(visit[p])

                    continue;

                visit[p] = true;

                for(int j = 1; j <= table[p][0]; j++){

                    int z = table[p][j]; 

                    if(z == last)

                        return level+1;

                    if(visit[z] == false && alreadyAdd[z] == false){

                        stack1[idx1] = z;

                        alreadyAdd[z] = true;  

                        idx1++;

                    }

                }

            }

            idx2 = 0;

        }

        level++;

    }

    

    return 0;

}

----------Explanation :-
Functionality:

This code implements the ladderLength function, which calculates the minimum number of word transformations (single-character changes) required to transform a starting word into a target word using a list of allowed words (the "wordList"). It uses a Breadth-First Search (BFS) algorithm to explore possible transformation paths and find the shortest one.

Key Steps:

Preprocessing:

Create a 2D array table to store the distance between pairs of words in the wordList.
Initialize table:
Each row i represents the distances from word i to other words.
table[i][0] stores the number of direct neighbors (one character difference) of word i.
table[i][j] stores the distance (number of transformations) from word i to word j (if known), otherwise 0.
Calculate table entries:
Iterate through all word pairs (i and j).
If they differ by only one character, mark j as a neighbor of i by updating table[i][table[i][0]++] = j.
If there's more than one difference, they are not neighbors.
BFS Exploration:

Create two stacks stack1 and stack2 to store words at different levels of exploration.
Initialize stack1 with words that differ from the starting word by one character.
If no such words exist, return 0 (no path possible).
Create a visit array to mark visited words and avoid cycles.
Create an alreadyAdd array to track words added to the search at each level, preventing duplicates.
Set level to 2 (one transformation already done).
While either stack is not empty:
Level Processing:
Process the stack with words at the current level:
For each word p in the stack:
Mark p as visited.
Iterate through its neighbors in table[p]:
If a neighbor z is the ending word, return level + 1 (path found).
If z has not been visited and not added at the current level, add it to the other stack (stack1 or stack2).
Empty the current stack.
Increment level to explore words at the next transformation depth.
Result:

If the BFS exploration completes without finding a path, return 0.
