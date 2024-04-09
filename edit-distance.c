**Edit Distance**

Problem Statement 147) Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.

----------------------------------------------------------------------------------
SOLUTION = int minDistance(char * word1, char * word2) {
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m + 1][n + 1];

    // Base cases: empty strings have edit distance equal to their lengths
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    // Build the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // No operation needed for matching characters
            } else {
                dp[i][j] = 1 + fmin(dp[i - 1][j],  // Deletion
                                   fmin(dp[i][j - 1],  // Insertion
                                        dp[i - 1][j - 1]));  // Replacement
            }
        }
    }

    return dp[m][n];  // Edit distance is stored in the bottom-right corner
}


-----Explanation :- 
Initialization (Base Cases):

The code retrieves the lengths of word1 (m) and word2 (n) using strlen.
It creates a 2D integer array dp of size (m + 1) x (n + 1) to store the minimum edit distance required to transform substrings of word1 into substrings of word2.
It initializes the first row (dp[i][0]) and the first column (dp[0][j]) of dp. These represent the base cases:
Transforming an empty string (word1[0...i]) into word2[0...j] requires j deletions (inserting j characters into the empty string to get word2[0...j]), so dp[i][0] = i.
Transforming word1[0...i] into an empty string (word2[0...j]) requires i deletions (deleting all characters from word1[0...i]), so dp[0][j] = j.
Iterative Subproblem Calculations:

It uses nested for loops to iteratively fill the remaining cells in the dp array:
The outer loop (i) iterates from 1 to m, considering substrings of word1 from length 1 to m.
The inner loop (j) iterates from 1 to n, considering substrings of word2 from length 1 to n.
Inside the loops, for each cell dp[i][j], it calculates the minimum edit distance to transform word1[0...i-1] (length i-1) into word2[0...j-1] (length j-1) and store it in a temporary variable (temp).
Minimum Edit Distance Options:

The code then considers three possible edit operations and their costs:
No Edit (Match): If the characters at the end of both current substrings (word1[i-1] and word2[j-1]) are the same, then no edit is required. The minimum edit distance in this case remains the same as the minimum edit distance for the previous substrings (dp[i-1][j-1]).
Deletion: If the characters don't match, transforming word1[0...i-1] into word2[0...j] requires deleting the last character from word1[0...i-1]. The cost of this operation is 1 (deletion), and the minimum edit distance in this case is calculated as 1 + dp[i-1][j]. This considers the minimum edit distance for transforming the remaining substring of word1 (word1[0...i-1]) into word2[0...j] after the deletion.
Insertion: Similarly, transforming word1[0...i] into word2[0...j-1] requires inserting the character word2[j-1] into word1[0...i]. The cost of this operation is 1 (insertion), and the minimum edit distance in this case is calculated as 1 + dp[i][j-1]. This considers the minimum edit distance for transforming word1[0...i] into the remaining substring of word2 (word2[0...j-1]) after the insertion.
Replacement: If the characters don't match, transforming word1[0...i-1] into word2[0...j-1] requires replacing the last character of word1[0...i-1] with word2[j-1]. The cost of this operation is 1 (replacement), and the minimum edit distance in this case is calculated as 1 + dp[i-1][j-1]. This considers the minimum edit distance for transforming the remaining substrings of both strings after the replacement.
