**Word Break**

Problem Statement 131) Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.

-------------------------------------------------------------------------------------------------
SOLUTION = bool wordBreak(char* s, char** wordDict, int wordDictSize) 
{
	if(wordDict == NULL || wordDictSize==0) 
	{
		return false;
	}
	if (s == NULL) 
	{
		return true;
	}
	int len1 = strlen(s);
	int len2 = len1 +1;
	
	bool *possible=calloc(len2,sizeof(bool));
	possible[0] = true;
	for (int i = 0; i < len2; i++)
	{
		for (int k = 0; k< wordDictSize; k++)
		{            
            if(possible[i])
            {
                int tmp=strlen(wordDict[k]);
                char str[tmp+1];
                strncpy(str,s+i,tmp);
                str[tmp]='\0';               
              
                if(strcmp(str,wordDict[k])==0)
                {                   
                    possible[i+tmp]=true;                    
                }
            }
			
		}
        
	}    
	return possible[len2-1];
}

-----Explanation :- 
Empty Dictionary/String Handling:

The code first checks for empty input:
If wordDict is NULL or wordDictSize is 0 (empty dictionary), it returns false as there are no words to form the string.
If s is NULL (empty string), it returns true as an empty string can be formed by concatenating no words.
Length Calculations:

It retrieves the length of the input string s (len1) and calculates a new length len2 that includes an extra space for the base case (explained later).
Dynamic Programming Array:

It allocates memory for a boolean array possible of size len2 using calloc. This array will be used to store whether a substring starting at a particular index can be formed using words in the dictionary.
The first element possible[0] is initialized to true because an empty string can always be formed.
Iterative Checks:

It uses nested for loops to iterate through the string s:
The outer loop (i) iterates from 0 to len2 - 1 (covering all possible starting indices of substrings).
The inner loop (k) iterates from 0 to wordDictSize - 1 (checking against all words in the dictionary).
Substring Matching:

Inside the nested loops, it checks if possible[i] is true. This indicates that the substring starting at index i can be formed using words in the dictionary.
If possible[i] is true:
It retrieves the length of the current word in the dictionary (tmp).
It declares a temporary character array str of size tmp + 1 to hold the potential matching substring.
It uses strncpy to copy tmp characters from s starting at index i into str.
It null-terminates str by assigning '\0' at index tmp.
It compares the copied substring (str) with the current word in the dictionary (wordDict[k]) using strcmp.
If strcmp returns 0 (meaning the strings are identical), it sets the corresponding element in the possible array (possible[i + tmp]) to true. This indicates that the substring starting at index i + tmp (which is the remaining part of the string after potentially using the current word) can also be formed using words in the dictionary.
Return the Result:

After iterating through all substrings and dictionary words, the final value in possible (at index len2 - 1) will indicate whether the entire string s can be formed using words from the dictionary. The function returns the value stored in possible[len2 - 1].
