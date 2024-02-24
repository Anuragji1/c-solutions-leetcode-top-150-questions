**Minimum Genetic Mutation**

Problem Statement 95) A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
 

Constraints:

0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

--------------------------------------------------------------------------------------------------
SOLUTION = int minMutation(char * start, char * end, char ** bank, int bankSize){
    int** table = malloc(bankSize * sizeof(int*));
    for(int i = 0; i < bankSize; i++){
        table[i] = malloc(bankSize * sizeof(int));
    }
    int last = -1;
    int pos;
    for(int i = 0; i < bankSize ; i++){
        table[i][0] = 0;
        if(strcmp(end, bank[i]) == 0)
            last = i;
        for(int j = 0; j < bankSize; j++){
            int d = 0;
            if(i == j)
                continue;
            for(int k = 0; k < 8; k++){
                if(bank[i][k] != bank[j][k])
                    d++;
                if(d > 1)
                    break;
            }
            if(d == 1){                 
                table[i][0]++;
                pos = table[i][0];   
                table[i][pos] = j; 
            }
        }
    }

    int* stack1 = malloc(10 * sizeof(int));
    int* stack2 = malloc(10 * sizeof(int));
    int idx1 = 0, idx2 = 0;
    for(int i = 0; i < bankSize; i++){
        int d = 0;
        for(int j = 0; j < 8; j++){
            if(start[j] != bank[i][j])
                d++;
            if(d > 1)
                break;
        }
        if(d == 1){
            if(i == last)
                return 1;
            stack1[idx1] = i;
            idx1++;
        }
    }
    if(idx1 == 0)
        return -1;
    int level = 1;
    bool* visit = calloc(bankSize, sizeof(int));
    bool flag = true;
    int cn = idx1 ;
    int p;
    while(idx1 > 0 || idx2 > 0){
        if(idx1 > 0){
            for(int i = 0; i < idx1; i++){
                p = stack1[i];
                visit[p] = true;
                for(int j = 1; j <= table[p][0]; j++){
                    int z = table[p][j]; 
                    if(z == last)
                        return level + 1;
                    if(visit[z] == false){
                        stack2[idx2] = z;
                        idx2++;
                    }
                }
            }
            idx1 = 0;            
        }
        else{
            for(int i = 0; i < idx2; i++){
                p = stack2[i];
                visit[p] = true;
                for(int j = 1; j <= table[p][0]; j++){
                    int z = table[p][j]; 
                    if(z == last)
                        return level+1;
                    if(visit[z] == false){
                        stack1[idx1] = z;
                        idx1++;
                    }
                }
            }
            idx2 = 0;
        }
        level++;
    }
    
    return -1;

}

--------------Explanation:- 
Functionality:

This code implements the minMutation function, which calculates the minimum number of mutations required to transform a starting DNA sequence into an ending DNA sequence using a given list of intermediate DNA sequences (the "bank"). It employs a Breadth-First Search (BFS) algorithm to explore possible mutation paths and identify the shortest one.

Key Steps:

Preprocessing:

Create a 2D array table to store the distance between pairs of sequences in the bank.
Initialize table:
Each row i represents the distances from sequence i to other sequences.
table[i][0] stores the number of direct neighbors (one mutation away) of sequence i.
table[i][j] stores the distance (number of mutations) from sequence i to sequence j (if known), otherwise 0.
Calculate table entries:
Iterate through all bank sequences i and j.
If they are different, count the number of mismatches (d).
If there is only one mismatch (d == 1), mark j as a neighbor of i by updating table[i][table[i][0]++] = j.
Find the index of the ending sequence (last) in the bank for faster lookup.
BFS Exploration:

Create two stacks stack1 and stack2 to store sequences at different levels of exploration.
Initialize stack1 with sequences that differ from the starting sequence by one mutation.
If no such sequences exist, return -1 (no path possible).
Set level to 1 to track the mutation depth.
Create a visit array to mark visited sequences and avoid cycles.
While either stack is not empty:
Level Processing:
Process the stack with sequences at the current level:
For each sequence p in the stack:
Mark p as visited.
Iterate through its neighbors in table[p]:
If a neighbor z is the ending sequence, return level + 1 (path found).
If z has not been visited, add it to the other stack (stack1 or stack2).
Empty the current stack.
Increment level to explore sequences at the next mutation depth.
Result:

If the BFS exploration completes without finding a path, return -1.
Key Points:

The code efficiently uses BFS to explore possible mutation paths in a level-by-level manner.
It precomputes the distances between sequences in the bank using table for faster neighbor lookup.
The visit array prevents infinite loops by marking visited sequences.
The code is well-structured and includes comments for better understanding.
