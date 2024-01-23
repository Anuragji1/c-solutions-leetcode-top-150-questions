**Longest Substring Without Repeating Characters**

Problem Statemnet 31) Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

--------------------------------------------------------------------------------------------------
SOLUTION = #define MAX(a, b) ((a) > (b) ? (a) : (b))

int lengthOfLongestSubstring(char * s)
{
    int counts[512];
    int i, n = strlen(s), win_start = 0;
    int best = 0;
    
    memset(counts, 0, sizeof(int) * 512);

    for (i = 0; i < n; i++) {
        int c = s[i];
        if (counts[c] >= 1) {
            assert(counts[c] == 1);
            // need to move the window until removing the instance of c
            while (win_start < i) {
                int to_del = s[win_start];
                counts[to_del]--;
                win_start++;                
                if (counts[c] == 0)
                    break;
            }
        }
        counts[c]++;
        best = MAX(best, i - win_start + 1);
    }
    
    return best;
}

--------------------Explanation :-
Function Overview:

lengthOfLongestSubstring finds the length of the longest substring within a given string that contains unique characters (no duplicates).
It employs a sliding window technique and a character frequency array for efficient tracking.
Key Elements:

**counts: Array of size 512 (assuming ASCII characters) to store character frequencies within the current window.
**n: Length of the input string s.
**win_start: Index marking the beginning of the current window.
**best: Variable storing the maximum length of a unique character substring found so far.
Algorithm:

Initialization:

Set all elements in counts to 0.
Initialize win_start, best, and i to 0.
Sliding Window:

Iterate through the string using i:
Get the current character c.
If counts[c] is already 1 (character seen before in the current window):
Move win_start forward until the previous occurrence of c is excluded from the window, maintaining the unique character property.
Increment counts[c] to reflect its presence in the window.
Update best if the current window size is larger than the previous maximum.
Return Result:

Return best, representing the length of the longest unique character substring.
