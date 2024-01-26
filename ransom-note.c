**Ransom Note**

Problem Statement 39) Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

-----------------------------------------------------------------------------------------------
SOLUTION = bool canConstruct(char* ransomNote, char* magazine) {
    int letterCounts[26] = {0};
    int i;

    // Count letter frequencies in magazine
    for (i = 0; magazine[i] != '\0'; i++) {
        letterCounts[magazine[i] - 'a']++;
    }

    // Check if each letter in ransomNote has enough count in magazine
    for (i = 0; ransomNote[i] != '\0'; i++) {
        if (--letterCounts[ransomNote[i] - 'a'] < 0) {
            return false; // Not enough letters in magazine
        }
    }

    return true; // Ransom note can be constructed
}

--------------------------------------Explanation :-
Purpose:

This code determines whether a ransom note can be constructed using the letters from a given magazine.
Function Breakdown:

Initializing Letter Counts:

letterCounts array stores the frequency of each letter (a-z) in the magazine, initially set to 0.
Counting Letters in Magazine:

The first loop iterates through each letter in the magazine:
The index in letterCounts is calculated by subtracting 'a' from the letter, providing a 0-25 index for each letter.
The corresponding count in letterCounts is incremented for each occurrence of the letter.
Checking Ransom Note:

The second loop iterates through each letter in the ransomNote:
The same index calculation is used to access the letter's count in letterCounts.
The count is decremented to "use" a letter from the magazine for the ransom note.
If the count becomes negative, it means there aren't enough letters in the magazine, and the function returns false.
Ransom Note Constructable:

If the loop completes without returning false, it means all letters in the ransom note have sufficient counts in the magazine, and the function returns true.
Key Points:

Space Complexity: O(1) space, using a fixed-size array for letter counts.
Time Complexity: O(m + n) time, where m and n are the lengths of the magazine and ransom note, respectively, due to two loops of comparable lengths.
Case Sensitivity: The code assumes lowercase letters only.
