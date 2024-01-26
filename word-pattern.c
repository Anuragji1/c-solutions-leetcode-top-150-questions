**Word Pattern**

Problem Statement 41) Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.

-------------------------------------------------------------------------------------------------------------------------
SOLUTION = // RS Hash Function
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
int cmp(const void* a, const void* b){
    return *(unsigned int*)a - *(unsigned int*)b;
}
bool wordPattern(char * pattern, char * s){
    int* hash = calloc( 26 , sizeof(int));
    int idx = 0;
    int n = strlen(s);
    int p_n = strlen(pattern);
    int begin = 0;
    for(int i = 0; i < n ;i++){
        if(s[i] == ' ' ){
            s[i] = '\0';
            unsigned int val = RSHash(&s[begin]);
            begin = i + 1;
            if(hash[pattern[idx] - 'a'] == 0){
                hash[pattern[idx] - 'a'] = val;
            }
            else if(hash[pattern[idx] - 'a'] != val)
                return false;
            idx++;
            if(idx == p_n)
                return false;
        }
        else if(i == n-1){
            unsigned int val = RSHash(&s[begin]);
            begin = i + 1;
            if(hash[pattern[idx] - 'a'] == 0){
                hash[pattern[idx] - 'a'] = val;
            }
            else if(hash[pattern[idx] - 'a'] != val)
                return false;
            idx++ ;  
            if(idx < p_n)
                return false;
        }
    }
    qsort(hash, 26, sizeof(unsigned int), cmp);
    for(int i = 0; i < 26; i++){
        if(hash[i] != 0){
            if(hash[i] == hash[i-1])
                return false;
        }
    }
    free(hash);
    return true;
}

-------------------------------Explanation :-
Purpose:

This code determines whether a given string s matches the pattern defined by pattern, where each letter in pattern maps to a unique word in s.
Function Breakdown:

RS Hash Function:

RSHash calculates a hash value for a given string using a specific algorithm.
Comparison Function:

cmp is used to compare unsigned integers for sorting.
wordPattern Function:

Initialization:
hash array stores hash values for words mapped to letters.
idx tracks the current position in pattern.
n and p_n store lengths of s and pattern.
begin marks the start of the current word in s.
Iterating through s:
The loop processes each character in s:
If a space is encountered:
Replace the space with a null terminator to isolate the word.
Calculate the hash value of the word using RSHash.
Check if the hash value matches the stored value for the current letter in pattern:
If not equal, return false (no match).
If not yet stored, store the hash value.
Move to the next character in pattern.
If it's the last character:
Perform similar steps as for spaces.
Ensure idx matches p_n for a complete match.
Sorting and Checking for Duplicates:
Sort the hash array to bring potential duplicates together.
Iterate through the sorted hash array:
If consecutive elements are equal, return false (duplicate words).
Return True:
If all checks pass, return true, indicating a match.
Key Points:

Hashing for Word Mapping: Uses hashing to efficiently check for word-letter mappings.
Duplicate Detection: Ensures each word maps to a unique letter.
Time Complexity: O(n log n) due to sorting, where n is the length of s.
Space Complexity: O(1) for fixed-size arrays, but O(n) if RSHash uses dynamic allocation.
