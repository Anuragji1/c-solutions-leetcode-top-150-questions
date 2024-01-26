**Valid Anagram**

Problem Statement 42) Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.

--------------------------------------------------------------------------------------------------------------------------
SOLUTION = bool isAnagram(char *s, char *t) {
    int n1 = strlen(s), n2 = strlen(t);
    if (n1 != n2) return false; // Different lengths, not anagrams

    int counts[26] = {0};  // Array to store letter frequencies

    // Count frequencies of letters in s
    for (int i = 0; i < n1; i++) {
        counts[s[i] - 'a']++;
    }

    // Decrease frequencies of letters in t
    for (int i = 0; i < n2; i++) {
        counts[t[i] - 'a']--;
        if (counts[t[i] - 'a'] < 0) return false; // t has extra letters
    }

    // Check if all frequencies are zero (all letters match)
    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) return false;
    }

    return true; // All checks passed, anagrams
}


-----------------------------Explanation :-
Purpose:

This code determines whether two given strings, s and t, are anagrams, meaning they contain the same letters in the same frequency, but potentially in a different order.
Function Breakdown:

Initial Checks:

Calculate the lengths of s and t. If they're different, return false immediately, as anagrams must have the same length.
Counting Letter Frequencies:

Create an array counts of size 26 to store the frequency of each lowercase letter (assuming ASCII characters).
Iterate through s and increment the corresponding count in counts for each letter.
Checking Letter Matches:

Iterate through t and decrement the corresponding count in counts for each letter.
If a count becomes negative, it means t has extra letters that are not in s, so return false.
Ensuring Complete Match:

Iterate through counts and check if all values are 0. If any value is not 0, it means some letters don't have matching frequencies, so return false.
Anagram Found:

If all checks pass, return true, indicating that s and t are anagrams.
Key Points:

Efficient Frequency Tracking: Uses an array to efficiently track letter frequencies.
Early Termination: Returns false as soon as a mismatch is found, avoiding unnecessary computations.
Time Complexity: O(n) time, where n is the length of the strings, due to single-pass loops.
Space Complexity: O(1) space, using a fixed-size array for letter frequencies.
Character Set: The code assumes lowercase ASCII letters only.
