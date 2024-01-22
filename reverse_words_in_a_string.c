**Reverse Words in a String**

Problem Statement 21) Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

-------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = char* reverse_word (char* s, int j, int i) {
    char t;
    while (j < i) {
        t = s[i];
        s[i--] = s[j];
        s[j++] = t;
    }
    return s;
}

char * reverseWords(char * s){
    
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int x = 0;
    char t;
    while (s[i] != '\0') {
        if (s[i] == ' ') {
            i++;
            continue;
        }
        j = i;
        while (s[i] != ' ') {
            i++;
            if (s[i] == '\0')
                break;
        }
        s = reverse_word(s, j, i-1);
    }
    
    i = 0;
    j = strlen(s) -1;
    while ( i < j) {
        t = s[i];
        s[i++] = s[j];
        s[j--] = t;
    }
    
    i = 0;
    j = 0;
    
    while (s[i] == ' ') {
        i++;
    }
    s = s+i;
    i = 0;
    x = strlen(s) -1;
    while (s[x] == ' ')
        x--;
    s[++x] = '\0';
    while (s[i] != '\0') {
        while (s[i] != '\0' && s[i] == ' '){
            i++;
            if (s[i] != ' ')
                s[j++] = ' ';
        }
        while (s[i] != '\0' && s[i] != ' ') {
            s[j++] = s[i++];
        }
        if (s[i] == '\0')
            s[j] = '\0';
    } 

    return s;
}

---------------------------------Explanation:- 
1. Word reversal:

The reverse_word function takes a string, starting and ending indices of a word within the string.
It swaps characters within the specified range using a temporary variable (t) to effectively reverse the word order.
2. Individual word reversal:

The main reverseWords function iterates through the string character by character:
If it encounters a space, it moves on to the next non-space character (skipping extra spaces).
Once it finds the beginning of a word, it stores the index (j) and keeps iterating until it reaches the end of the word (either another space or the string end).
It calls the reverse_word function with the identified word indices to reverse its order within the main string.
3. Entire string reversal:

After iterating through all words, the code reverses the entire string again using the same swapping technique in a separate loop (indices i and j). This step ensures the overall order of words is reversed as well.
4. Trim leading and trailing spaces:

The code then iterates through the string again, removing any leading spaces by adjusting the starting index (i).
It finds the last non-space character (x) and adds a null terminator ('\0') one position after it, effectively trimming trailing spaces.
Finally, it iterates through the remaining string, replacing repeated spaces with single spaces and maintaining the order of non-space characters.
