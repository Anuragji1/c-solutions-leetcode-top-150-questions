**Text Justification**

Problem Statement 24) Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
 

Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
Note that the second line is also left-justified because it contains only one word.
Example 3:

Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 

Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = #define RES_LEN 300

char ** fullJustify(char ** words, int wordsSize, int maxWidth, int* returnSize){
    int spaces, pad, remainSpaces, lWidth, cWordLen;
    // allocate memory for the result
    char **res = calloc(sizeof(char *),  RES_LEN);
    for(int i = 0; i < RES_LEN; i++)
        res[i] = calloc(sizeof(char), maxWidth + 1);
    *returnSize = 0;
    int cLen = 0;
    
    for(int l = 0, r; l < wordsSize; l = r) {
        // find words that can fit to form a current line in result
        r = l;
        lWidth = 0; 
        cWordLen = strlen(words[r]);
        while(r < wordsSize && cWordLen + lWidth + r - l <= maxWidth) {
            lWidth += cWordLen;
            r++;
            if(r < wordsSize)
                cWordLen = strlen(words[r]);
        }
        
        // calculate the spaces and extra spaces to pad after each word in this line
        spaces = 1;
        pad = 0;
        if(r - l != 1 && r != wordsSize) {
            spaces = (maxWidth - lWidth) / (r - l - 1);
            pad = (maxWidth - lWidth) % (r - l - 1);
        }
        
		// Now, words from left to right pointers can be added to current line by justifying. 
        // Add the left most word first. Then, add all the spaces and extra padded spaces.
		// Then, add the next word 
        cLen = 0;
        cLen += sprintf(res[*returnSize], "%s", words[l]);
        for(int w = l + 1; w < r; w++) {										
            for(int i = 0; i < spaces; i++)									// append spaces after current word
                cLen += sprintf(res[*returnSize] + cLen, "%c", ' ');

            // pad extra space for words in line from left to right 
            if(pad-- > 0)													// append extra padded spaces in left justified manner                
                cLen += sprintf(res[*returnSize] + cLen, "%c", ' ');
            
            cLen += sprintf(res[*returnSize] + cLen, "%s", words[w]);            
        }
        
        // Adjust the last line by appending remaining spaces to the right
        remainSpaces = maxWidth - cLen;
        for(int i = 0; i < remainSpaces; i++)
            cLen += sprintf(res[*returnSize] + cLen, "%c", ' ');
        
        (*returnSize)++;
    }
    return res;
}

---------------------------------------Explanation :-
Key elements:

words: Array of pointers to null-terminated C strings representing words.
wordsSize: Number of words in the words array.
maxWidth: Maximum width of each justified line.
res: Array of dynamically allocated character pointers for storing the result lines.
returnSize: Integer pointer to keep track of the number of lines in the result.
cLen: Current length of the string being built in the current line.
l: Left pointer iterating through the words array for forming lines.
r: Right pointer iterating through the words array to find words fitting in the current line.
lWidth: Current width of the line considering word lengths.
cWordLen: Length of the current word being considered.
spaces: Number of spaces to put between words in the current line.
pad: Number of extra spaces to distribute unevenly after each word in the current line.
Algorithm:

Initialization:

Allocate memory for the res array and its internal strings.
Initialize returnSize and cLen to 0.
Iterating through words:

Use a loop with left and right pointers (l and r) iterating through the words array:
Within the loop:
Find consecutive words that can fit in the current line under the maxWidth constraint. Update r accordingly.
Calculate the number of regular spaces (spaces) and extra spaces (pad) to distribute between words based on line width and number of words.
Building and justifying lines:

For each line:
Add the first word directly to the current result string in res.
Loop through remaining words in the line:
Add regular spaces (using spaces counter) to separate words.
Optionally add an extra space if available (pad-- > 0) in a left-justified manner.
Add the next word to the result string.
If this is not the last line, calculate the remaining spaces available and append them to the right to justify the line.
Increment returnSize to track the number of lines created.
Return result:

The res array now contains pointers to dynamically allocated strings representing each justified line.
returnSize indicates the number of lines in the result.
Key points:

The code efficiently calculates spaces and extra padding based on line width and word count.
It handles special cases for the last line and unevenly distributes extra spaces for justified alignment.
It uses dynamic memory allocation for storing the result strings in the res array.
