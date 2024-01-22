**Find the Index of the First Occurrence in a String**

Problem Statement 23) Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int strStr(char * haystack, char * needle){
    int hLen = strlen(haystack);
    int nLen = strlen(needle);

    if (nLen == 0) {  // Handle empty needle case
        return 0;
    }

    for (int i = 0; i <= hLen - nLen; i++) {
        int j = 0;
        for (; j < nLen; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == nLen) {
            return i;
        }
    }

    return -1;  // Not found
}


-------------------------Explanation :-
Key elements:

haystack: Pointer to the null-terminated C string containing the larger text to search.
needle: Pointer to the null-terminated C string representing the substring to search for.
hLen: Integer variable storing the length of the haystack string.
nLen: Integer variable storing the length of the needle string.
Algorithm:

Edge case handling:

Check if the needle string is empty. If so, the substring is always found (at position 0), and the function returns 0.
Looping through haystack:

Use a loop iterating from 0 to the length of haystack minus the length of needle (to avoid out-of-bounds comparisons).
Within the loop, initialize another index j to 0 for iterating through the needle string.
Character comparison:

Within the nested loop for needle:
Compare the characters at the current positions (i + j in haystack and j in needle).
If any character mismatch is found, break the inner loop, as the current starting position in haystack cannot be the beginning of the desired substring.
Successful match:

If the inner loop completes iterating through the entire needle string (meaning all characters matched), it signifies a successful match.
The current index i from the outer loop points to the starting position of the found substring in the haystack.
Return this index (i) as the result.
Not found:

If the outer loop finishes iterating without finding a matching substring, it signifies the needle is not present in the haystack.
Return -1 to indicate the substring was not found.
Key points:

The code efficiently utilizes nested loops to compare characters at corresponding positions in both strings.
It handles edge cases like empty needles.
The use of break statements optimizes the search by stopping further comparison after a character mismatch.
