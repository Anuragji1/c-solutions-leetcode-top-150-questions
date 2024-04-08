**Interleaving String**

Problem Statement 146) Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

 

Example 1:


Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
Output: true
Explanation: One way to obtain s3 is:
Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
Since s3 can be obtained by interleaving s1 and s2, we return true.
Example 2:

Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
Output: false
Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
Example 3:

Input: s1 = "", s2 = "", s3 = ""
Output: true
 

Constraints:

0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1, s2, and s3 consist of lowercase English letters.
 

Follow up: Could you solve it using only O(s2.length) additional memory space?


-------------------------------------------------------------------------------------------------------------------
SOLUTION = bool isInterleave(char * s1, char * s2, char * s3){
    int m = strlen(s1), n = strlen(s2), t = strlen(s3);
    if (m + n != t) return false; // Lengths must match

    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    // Base cases: empty strings
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
    for (int j = 1; j <= n; j++) dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];

    // Dynamic programming: build up solutions for larger substrings
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                       (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }

    return dp[m][n]; // Final result indicates whether full strings interleave
}

-----Explanation :-
This code determines whether a given string s3 is an interleaving of two other strings s1 and s2. An interleaving means that s3 can be formed by interweaving characters from s1 and s2 in a way that preserves the relative order of characters within each original string.

Approach: Dynamic Programming

The code employs dynamic programming to solve this problem efficiently:

Initialization and Length Check:

It gets the lengths of s1, s2, and s3 using strlen.
It immediately returns false if the combined length of s1 and s2 doesn't equal the length of s3, as interleaving is impossible in that case.
It creates a 2D boolean array dp with dimensions (m + 1) and (n + 1) to store interleaving possibilities for substrings.
Base Cases:

It sets dp[0][0] to true, indicating that empty strings can always be interleaved to form an empty string.
It iterates through dp[i][0] and dp[0][j] rows to set values for cases where one of the strings is empty. It checks if characters from the non-empty string match corresponding characters in s3 and propagate the possibility of interleaving from previous cells.
Building Solutions for Larger Substrings:

It utilizes nested for loops to iterate through remaining cells of dp:
For each dp[i][j], it checks two possible ways to form an interleaving:
Taking a character from s1 and checking if the remaining substrings (s1[i-1:] and s2) interleave to form the remaining part of s3 (s3[i+j-1:]). This is represented by dp[i - 1][j] && s1[i - 1] == s3[i + j - 1].
Taking a character from s2 and checking if the remaining substrings (s1 and s2[j-1:]) interleave to form the remaining part of s3. This is represented by dp[i][j - 1] && s2[j - 1] == s3[i + j - 1].
If either of these possibilities is true, it means an interleaving exists, and dp[i][j] is set to true.
Final Result:

The value of dp[m][n], representing the interleaving possibility for the entire strings, is returned as the final result, indicating whether s3 is a valid interleaving of s1 and s2.
