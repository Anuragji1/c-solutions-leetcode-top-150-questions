**Length of Last Word**

Problem Statement 19) Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.

-----------------------------------------------------------------------------------------------------------------------------
SOLUTION = int lengthOfLastWord(char * s){
    int len = strlen(s), wordLen = 0;
    int i = len - 1;

    while (i >= 0 && s[i] == ' ') i--;  // Trim trailing spaces

    while (i >= 0 && s[i] != ' ') {
        wordLen++;
        i--;
    }

    return wordLen;
}

----------------------Explanation :- 
Key elements:

s: Pointer to the null-terminated string containing the target text.
len: Integer variable storing the length of the string s.
wordLen: Integer variable accumulating the length of the last word.
i: Integer variable used as an index to iterate through the string s backwards.
Algorithm:

Preprocessing:

Get the len of the string s using strlen.
Initialize wordLen to 0 to track the length of the last word.
Set i to the last index of the string (len - 1).
Trim trailing spaces:

Use a loop while i is non-negative and the character at s[i] is a space:
Decrement i to move to the previous character in the string.
This loop effectively removes any trailing spaces from the string before counting the last word.
Count last word length:

Use another loop while i is non-negative and the character at s[i] is not a space:
Increment wordLen to count the characters in the last word.
Decrement i to move to the previous character in the string.
This loop iterates through the non-space characters of the last word until it reaches the beginning of the string or a space.
Return result:

After the loop finishes, wordLen holds the length of the last word, which is returned as the function's result.
