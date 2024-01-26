**Isomorphic Strings**

Problem Statement 40) Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
 

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

----------------------------------------------------------------------------------------------------
SOLUTION = bool isIsomorphic(char *s, char *t) {
    int m1[256] = {0}, m2[256] = {0}, n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (m1[s[i]] != m2[t[i]]) return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

------------------------------------Explanation :-
Purpose:

This code determines whether two given strings, s and t, are isomorphic, meaning they have the same structure in terms of character mapping.
Function Breakdown:

Initializing Maps:

m1 and m2 arrays act as maps to track the positions of characters in s and t, respectively. They're initialized to 0.
n stores the length of s (and t, since they're assumed to be the same length).
Iterating and Comparing Characters:

The loop iterates through each character in both strings simultaneously:
If the current indices of s[i] and t[i] in their respective maps (m1 and m2) are different, it means the characters don't have a consistent mapping, so the function returns false.
Otherwise, the indices of s[i] and t[i] in their respective maps are both set to i + 1, indicating their matching positions.
Isomorphic Strings:

If the loop completes without returning false, it means all characters have a consistent mapping, and the function returns true.
Key Points:

Mapping Characters: The code uses arrays as maps to efficiently track character positions and their mappings.
Time Complexity: O(n) time, where n is the length of the strings, due to a single loop iterating through both strings.
Space Complexity: O(1) space, using fixed-size arrays for character mapping.
Character Set: The code assumes ASCII characters (0-255).
