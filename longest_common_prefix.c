**Longest Common Prefix**

Problem Statement 20) Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.

---------------------------------------------------------------------------------------------------------------------
SOLUTION = char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) return "";
    if (strsSize == 1) return strs[0];

    int len = 0, min = strlen(strs[0]);
    for (int i = 1; i < strsSize; ++i) {
        min = strlen(strs[i]) < min ? strlen(strs[i]) : min;
    }

    for (int c = 0; c < min; ++c) {
        for (int s = 0; s < strsSize - 1; ++s) {
            if (strs[s][c] == strs[s+1][c]) {
                if (s == strsSize - 2) {
                    ++len;
                }
            } else {
                goto br;
            }
        }
    }
    br:

    if (len > 0) {
        char* ret = malloc(len * sizeof(int));
        strs[0][len] = '\0';
        strcpy(ret, strs[0]);
        return ret;
    }

    return "";
}

-------------------------Explanation :-
Key elements:

strs: Array of pointers to null-terminated C strings.
strsSize: Integer representing the number of strings in the strs array.
len: Integer variable accumulating the length of the common prefix.
min: Integer variable holding the minimum length of all strings in the strs array.
** algorithm:**

Edge cases:

If strsSize is 0 (empty array), return an empty string.
If strsSize is 1 (only one string), return that string as the common prefix.
Find minimum length:

Iterate through all strings (except the first) and find the shortest one to determine the upper bound for the common prefix length.
update min with the shorter length if found.
Iterate through characters:

loop through characters until the minimum length or beyond.
for each character position:
iterate through all pairs of consecutive strings in the array.
compare the characters at the current position in each pair.
if they match, continue comparing to the next pair.
if any pair mismatches, break the inner loop (signifying no further common prefix can exist).
Handle results:

if the character loop reached its full extent (len is greater than 0), it signifies a common prefix found.
allocate memory for a new string based on the len.
copy the common prefix substring (up to the null terminator) from the first string (chosen as reference) to the newly created string.
return the pointer to the newly created string as the results.
Empty prefix:

if the character loop did not reach its full extent ( no matching characters found), it signifies no common prefix exists.
return an empty string as the result.
