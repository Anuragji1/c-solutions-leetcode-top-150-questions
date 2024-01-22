**Valid Palindrome**

Problem Statement 25) A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

---------------------------------------------------------------------------------------------------------------
SOLUTION = bool isPalindrome(char * s){
    int left = 0, right = strlen(s) - 1;

    while (left < right) {
        // Find the next alphanumeric character from the left
        while (left < right && !isalnum(s[left])) {
            left++;
        }

        // Find the next alphanumeric character from the right
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        // Compare the characters after converting to lowercase
        if (tolower(s[left++]) != tolower(s[right--])) {
            return false;
        }
    }

    return true;
}

-------------------------------------Explanation :-
Key elements:

s: Pointer to the null-terminated C string to be checked.
left: Integer index starting from the left side of the string.
right: Integer index starting from the right side of the string.
Algorithm:

Loop for comparison:

Use a loop while left is less than right:
Within the loop:
Skip non-alphanumeric characters from the left: Use a nested loop to move left forward until it encounters an alphanumeric character (using isalnum).
Skip non-alphanumeric characters from the right: Similarly, use a nested loop to move right backward until it encounters an alphanumeric character.
Compare characters after converting to lowercase: Compare the characters at left and right after converting them to lowercase using tolower.
If the characters don't match, return false as the string is not a palindrome.
Otherwise, increment left and decrement right to move towards the center of the string for further comparisons.
Palindrome result:

If the loop completes without encountering a mismatch, it means all compared characters were the same (or their lowercase equivalents).
Therefore, the function returns true, indicating the string is a palindrome.
Key points:

The code efficiently handles non-alphanumeric characters by skipping them before comparison.
It ensures case-insensitive comparison by converting characters to lowercase before checking for equality.
The loop structure effectively iterates towards the center of the string, stopping if any mismatch is found.
