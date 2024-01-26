**Group Anagrams**

Problem Statement 44) Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

-----------------------------------------------------------------------------------------------------
SOLUTION = // sort last item
int cmpfunc( const void* p1,  const void* p2){
   int* arr1 = *(int**)p1;
   int* arr2 = *(int**)p2;
  if(arr1[2] == arr2[2]) 
      return arr1[1] - arr2[1]; 
  return arr1[2] - arr2[2];
}

//sort string
int cmpStr(const void* a, const void* b){
    return *(char*)a - *(char*)b;
}

unsigned int RSHash(char *str)
{
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	while (*str)
	{
		hash = hash * a + (*str++);
		a *= b;
	}

	return (hash & 0x7FFFFFFF);
}

//string sort first, then use RSHash
int hash(char* s){
    int len = strlen(s);
    char* temp = malloc((len+1) * sizeof(char));
    strcpy(temp, s);
    qsort(temp, len, sizeof(char), cmpStr);
    int ans = RSHash(temp);
    free(temp);
    return ans;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int i, j;
    int** lenTable = malloc(strsSize * sizeof(int*)); 
    
    for(i = 0; i  < strsSize; i++){
        lenTable[i] = malloc(3 * sizeof(int));
        lenTable[i][0] = i;
        lenTable[i][1] = strlen(strs[i]);
        lenTable[i][2] = hash(strs[i]);
    }
    
    qsort(lenTable, strsSize, sizeof(int*), cmpfunc);
    int l = lenTable[0][1];
    int cn = 1;
    char*** ans = malloc(10000 * sizeof(char**));
    *returnColumnSizes = malloc(10000 * sizeof(int));
    int idx = 0;
    for(i = 1; i < strsSize; i++){
        if(lenTable[i][2] == lenTable[i-1][2]){
            cn++;
        }
        else{
            l = lenTable[i-1][1];
            ans[idx] = malloc(cn * sizeof(char*));
            returnColumnSizes[0][idx] = cn;
            for(j = 0; j < cn; j++){
                ans[idx][j] = malloc((l+1) * sizeof(char));
                //ans[idx][j][l] = '\0';
                strcpy(ans[idx][j], strs[lenTable[i-1-j][0]]);  
            }
            idx++;
            cn = 1;
        }
    }
    ans[idx] = malloc(cn * sizeof(char*));
    l = lenTable[i-1][1];
    returnColumnSizes[0][idx] = cn;
    for(j = 0; j < cn; j++){
        ans[idx][j] = malloc((l+1) * sizeof(char));
        //ans[idx][j][l] = '\0';
        strcpy(ans[idx][j], strs[lenTable[i-1-j][0]]);  
    }
    idx++;
    * returnSize = idx;
    *returnColumnSizes = realloc(*returnColumnSizes, idx*sizeof(int)) ;
    ans = realloc(ans, idx * sizeof(char**));
    return ans;
}

---------------------------Explanation:-
Purpose:

This code groups anagrams (words with the same letters in different arrangements) within a given array of strings.
Function Breakdown:

Auxiliary Functions:

cmpfunc: Sorts an array of integer arrays based on the last element (used for sorting anagrams).
cmpStr: Sorts characters alphabetically (used for string sorting within hash).
RSHash: Calculates a hash value for a string (used for efficient anagram detection).
hash: Sorts a string's characters alphabetically and then applies RSHash for a consistent hash value regardless of letter order.
groupAnagrams Function:

Initialization:

lenTable stores indices, lengths, and hash values of strings for sorting.
ans holds the grouped anagrams.
returnColumnSizes stores the number of anagrams in each group.
Hashing and Sorting:

Calculate hash values for each string using hash.
Sort lenTable based on hash values (and lengths if hash values are equal) using qsort and cmpfunc.
Grouping Anagrams:

Iterate through lenTable and group strings with the same hash value:
If the current string's hash matches the previous one, add it to the current group.
Otherwise, create a new group and add the current string to it.
Formatting Output:

Allocate memory for each group in ans and copy the grouped anagrams.
Set returnSize to the number of groups.
Resize ans and returnColumnSizes to the exact required sizes using realloc.
Return Result:

Return ans, a 3D array containing the grouped anagrams, along with returnSize and returnColumnSizes for group information.
Key Points:

Hashing for Anagrams: Uses hashing to efficiently identify anagrams, even with different letter arrangements.
Sorting for Grouping: Sorts strings based on hash values and lengths for efficient grouping.
Dynamic Memory Allocation: Manages memory dynamically for flexible output structure.
Time Complexity: O(n log n) due to sorting, where n is the number of strings.
Space Complexity: O(n) for temporary arrays and output structure.group-anagrams
