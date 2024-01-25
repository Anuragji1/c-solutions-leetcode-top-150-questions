**Minimum Window Substring**

Problem Statement 33) Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.

----------------------------------------------------------------------------------------------
SOLUTION = char * minWindow(char * s, char * t){
    int m = strlen(s);
    int n = strlen(t);

    int* alpha = calloc(52, sizeof(int));
    int* alphaCopy = calloc(52 , sizeof(int));
    for(int i = 0; i < n; i++){
        (t[i] >= 'a') ? alpha[t[i] - 'a']++ : alpha[t[i] - 'A' + 26]++;
    }
    
    int min = INT_MAX;
    int l = -1, r;
    int match = 0;
    int a_idx = -1;
    int r_key, l_key;
    for(r = 0; r < m; r++){
        r_key = (s[r] >= 'a') ? r_key = s[r] -'a' : s[r] -'A' + 26;

        if(alpha[r_key] > 0){
            if(l == -1)
                l = r;
            alphaCopy[r_key]++;
            if(alphaCopy[r_key] <= alpha[r_key]){
                match++;                
                if(match == n){
                    l_key = (s[l] >= 'a') ? s[l] -'a' : s[l] -'A' + 26; 
                    while(match == n || alpha[l_key] == 0){   
                        if(alpha[l_key] > 0){
                            alphaCopy[l_key]--; 
                            if(alphaCopy[l_key] < alpha[l_key]){
                                if((r-l+1) < min){
                                    min = r-l+1;
                                    a_idx = l;
                                }
                                match--;                                
                            }
                        }   
                        l++; 
                       if(l < m)
                            l_key = (s[l] >= 'a') ?  s[l] -'a' : s[l] -'A' + 26;
                       else
                          break;
                    }
                }
            }
        }
    }
    if(a_idx == -1)
        return "";
    char* ans = malloc((min + 1) * sizeof(char));
    ans[min] = '\0';
    strncpy(ans, &s[a_idx], min);
    return ans;
}

----------------------------------------Explanation :- 
Function Overview:

minWindow aims to find the minimum-length substring within a string s that contains all characters from another string t.
It employs a sliding window technique and character frequency tracking to achieve this efficiently.
Key Elements:

**alpha: Array of size 52 to store character frequencies in t (considering both lowercase and uppercase letters).
**alphaCopy: Copy of alpha to track character frequencies within the current window.
**l: Left pointer marking the beginning of the current window.
**r: Right pointer used to expand the window.
**match: Counter tracking the number of characters from t found in the current window.
**min: Stores the length of the smallest valid window found so far.
**a_idx: Stores the starting index of the smallest valid window.
Algorithm:

Initialization:

Calculate lengths of s and t.
Create and initialize alpha and alphaCopy arrays.
Set min to INT_MAX, l to -1, match to 0, and a_idx to -1.
Sliding Window:

Iterate through s using r pointer:
Calculate the character's index in the alpha array.
If the character is present in t:
If l is still -1, initialize it to r (start the window).
Increment the character's count in alphaCopy.
If the count in alphaCopy is within the allowed frequency in alpha:
Increment match.
If match equals the length of t:
Shrink the window from the left until it no longer contains all characters from t or a smaller window is found:
Decrement character counts in alphaCopy as you move l.
Update min and a_idx if a smaller window is found.
Decrement match when a character from t is no longer in the window.
Return Result:

If a valid window was found, allocate memory for the substring, copy the characters, and return it.
Otherwise, return an empty string.
Key Points:

Sliding Window Efficiency: The sliding window technique efficiently scans for valid substrings, avoiding redundant comparisons.
Character Frequency Tracking: alpha and alphaCopy arrays effectively track character frequencies, ensuring all characters from t are present in the window.
Window Shrinking: The inner loop efficiently shrinks the window to find the minimum-length substring.
Time Complexity: O(m + n), where m and n are the lengths of s and t, due to single passes through s and t.
Space Complexity: O(1), as it uses a fixed-size array regardless of input lengths
