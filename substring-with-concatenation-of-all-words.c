**Substring with Concatenation of All Words**

Problem Statement 32) You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

 

Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]
Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
The output order does not matter. Returning [9,0] is fine too.
Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []
Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
There is no substring of length 16 in s that is equal to the concatenation of any permutation of words.
We return an empty array.
Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.
 

Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.

-----------------------------------------------------------------------------------------------------------------------------
SOLUTION = #define newArray(type, size) ((type*)calloc(size, sizeof(type)))
#define resizeArray(ptr, type, size) ((type*)realloc(ptr, (size) * sizeof(type)))

int *pushback(int *array, int *size, int value) {
    int *output = resizeArray(array, int, *size + 1);
    output[(*size)++] = value;
    return output;
}

typedef struct {
    char *word;
    int occurs;
} wordEntry;

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int *result = NULL;
    *returnSize = 0;

    // edge conditions
    if (wordsSize <= 0)
        return result;
    int slength = strlen(s), wlength = strlen(words[0]);
    if (slength < wlength * wordsSize)
        return result;

    // handle words, count the duplicates.
    wordEntry *ws = newArray(wordEntry, wordsSize);
    int wsSize = 0, i, j, k;
    for (i = 0; i < wordsSize; ++i) {
        char *word = words[i];
        for (k = -1, j = 0; k < 0 && j < wsSize; ++j)
            if (strcmp(ws[j].word, word) == 0)
                k = j;
        if (k < 0)
            k = wsSize++;
        ws[k].word = word;
        ws[k].occurs++;
    }

    // calulate word matched at each position.
    slength -= wlength - 1;
    int *ms = newArray(int, slength);
    for (i = 0; i < slength; ++i) {
        for (k = -1, j = 0; k < 0 && j < wsSize; ++j)
            if (strncmp(s + i, ws[j].word, wlength) == 0)
                k = j;
        // store matched index in word list without duplicates.
        ms[i] = k;
    }

    // scan all possible chains, cached word indices stored in os.
    int *os = newArray(int, wordsSize);
    for (i = 0; i < wlength; ++i) {
        int start = i, found = 0;
        for (j = i; j < slength; j += wlength) {
            int windex = ms[j];
            if (windex < 0) {
                // no matched word here, simply reset the marker,
                // and write back all cached words.
                start = j + wlength;
                while (found > 0) {
                    ws[os[--found]].occurs++;
                }
                continue;
            }
            // move the matched word from word list to cache,
            // write back the leading cached words if necessary.
            if (ws[windex].occurs == 0) {
                for (k = 0; k < found; ++k) {
                    ws[os[k]].occurs++;
                    start += wlength;
                    if (os[k] == windex) {
                        ++k;
                        break;
                    }
                }
                found -= k;
                if (found)
                    memmove(os, os + k, found * sizeof(*os));
            }
            ws[windex].occurs--;
            os[found++] = windex;
            // push the marker position if matched all words.
            if (found == wordsSize)
                result = pushback(result, returnSize, start);
        }
        // after scanning, write back all cached words.
        while (found > 0) {
            ws[os[--found]].occurs++;
        }
    }

    free(ws);
    free(ms);
    free(os);

    return result;
}

----------------------------- Explanation :-
Function Overview:

findSubstring finds all starting indices of substrings within a given string s that are comprised of all words from a given array of words words, potentially with duplicates.
It employs a sliding window approach and efficient word tracking techniques.
Key Elements:

**words: Array of words to search for.
**wordsSize: Number of words in words.
**ws: Array of wordEntry structures to track word occurrences and manage duplicates.
ms: Array storing the index of the matched word in ws at each position in s.
os: Cache array to store indices of words currently in the sliding window.
start: Marks the beginning of the current sliding window.
found: Counts the number of words found in the current window.
Algorithm:

Preprocessing:

Handle edge cases (empty words or string too short).
Create ws array, storing words and their occurrences, handling duplicates.
Create ms array, mapping each position in s to the corresponding word index in ws.
Sliding Window:

Iterate through possible starting positions of the window (i):
Initialize start and found for the current window.
Iterate through the string in steps of word length (j):
Get the matched word index (windex) from ms.
If no match, reset the window and restore cached words.
If match found:
If the word's remaining occurrences are 0, adjust the window and cached words to maintain word order.
Decrement the word's occurrences in ws.
Add the word index to the cache (os).
If all words found, store the window start index in result.
Restore cached word occurrences after each window scan.
Return Result:

Free dynamically allocated arrays.
Return the result array containing starting indices of matching substrings.
Key Points:

Sliding Window Efficiency: The sliding window scans the string efficiently, avoiding redundant word matching.
Word Tracking with Duplicates: ws array effectively tracks word occurrences, including duplicates.
Caching for Word Order: os cache maintains word order within the window for accurate substring identification.
Time Complexity: O(n * w), where n is the string length and w is the word length, due to nested loops.
Space Complexity: O(n + w), primarily due to ms and os arrays.
