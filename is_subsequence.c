**Is Subsequence**

Problem Statement 26) Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

 

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true
Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
 

Constraints:

0 <= s.length <= 100
0 <= t.length <= 104
s and t consist only of lowercase English letters.

----------------------------------------------------------------------------------------------------------------------------------
SOLUTION = bool isSubsequence(char * s, char * t){
    int i = 0, j = 0;

    while (i < strlen(s) && j < strlen(t)) {
        if (s[i] == t[j]) {
            i++;  // Move to the next character in s only when a match is found
        }
        j++;  // Always move to the next character in t
    }

    return i == strlen(s);  // True if all characters in s were found
}

----------------------------Explanation :-
Key elements:

s: Pointer to the null-terminated C string representing the potential subsequence.
t: Pointer to the null-terminated C string representing the main string.
i: Integer index iterating through the s string.
j: Integer index iterating through the t string.
Algorithm:

Looping through strings:

The code uses a loop iterating over both i and j as long as their respective string lengths allow (avoiding out-of-bounds access).
Character comparison and advancement:

Within the loop:
It compares the characters at s[i] and t[j].
If they match, the i pointer is incremented to move to the next character in s. This signifies a successful match for the current character in the subsequence.
Crucially, the j pointer is always incremented regardless of the match. This allows checking for subsequences within t even if some characters in s are skipped (as long as the overall order is maintained).
Subsequence verification:

After the loop finishes iterating, the code checks if the i index reached the end of the s string.
If i equals the length of s, it means all characters in the subsequence were found within the main string, confirming it as a subsequence.
Otherwise, if i is less than the length of s, it signifies that some characters in the subsequence weren't found (mismatch or not enough characters in t), indicating s is not a subsequence of t.
Return result:

Based on the final value of i, the function returns true if s is a subsequence of t and false otherwise.
Key points:

The code efficiently iterates through both strings while ensuring the subsequence order is maintained in s.
It cleverly increments the j pointer regardless of the match, allowing for skipping characters in t without breaking the subsequence condition.
The final check on i verifies if all characters in s were found, confirming the subsequence relationship.
