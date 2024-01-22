**Zigzag Conversion**

Problem Statement 22) The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

--------------------------------------------------------------------------------------------------------------------------------
SOLUTION = typedef enum _DIR_STATE_EM_ {
    DOWN = 0,
    UP_RIGHT = 1
} dir_state_em;

char *convert(char *s, int numRows) {
    int length = strlen(s) + 1;
    if(length < numRows || numRows < 2) return s;

    /* build the string table, numRows X (strlen(s) / 2) */
    char **table = (char **)malloc(numRows*sizeof(char *));
    for(int i=0;i<numRows;i++) {
        table[i] = (char *)malloc(length/2*sizeof(char));
        memset(table[i], 0, length/2*sizeof(char));
    }

    /* New string */
    char *s_result = (char *)malloc(length*sizeof(char));
    memset(s_result, 0, length*sizeof(char));

    int i_s = 0;
    int r = 0;
    int c = 0;
    dir_state_em state = DOWN;
    int count = strlen(s);
    while(count > 0) {
        table[r][c] = s[i_s++];

        switch (state) {
            case DOWN:
                r++;
                if(r >= numRows) {
                    r--;
                    r--;
                    c++;
                    state = UP_RIGHT;
                }
                break;
            case UP_RIGHT:
                r--;
                c++;
                if(r < 0) {
                    r++;
                    r++;
                    c--;
                    state = DOWN;
                }
                break;
        }
        count--;
    }

    /* Print the table */
    i_s = 0;
    for(int i=0;i<numRows;i++) {
        for(int j=0;j<length/2;j++) {
            if(table[i][j] != 0) {
                // printf("%c, ", table[i][j]);
                s_result[i_s++] = table[i][j];
            }
            else {
                // printf("0, ");
            }
        }
        // printf("\n");
    }

    return s_result;
}

------------------------------------------------Explanation :-
Key Elements:

s: The original string to be converted.
numRows: The desired number of rows in the zig-zag layout.
table: A dynamically allocated 2D array of characters holding the intermediate string representation.
s_result: The final string after zig-zagging the characters.
i_s: Index for iterating through the original string.
r: Row index in the table.
c: Column index in the table.
state: Enum variable representing the direction of movement (DOWN or UP_RIGHT).
count: Remaining characters to be processed in the original string.
Algorithm:

Validation and initialization:

Check if the string length is less than numRows or numRows is less than 2 (invalid cases); return the original string if so.
Allocate memory for the table and s_result arrays.
Initialize i_s, r, c, state, and count to their starting values.
Zigzagging characters:

Enter a loop while there are still characters to process (count > 0).
Add the current character from s at the current position (table[r][c]).
Update i_s to move to the next character in the original string.
Switch the direction (state) based on the current position and row boundaries:
If going DOWN, increase r (move down one row).
If reaching the bottom row, flip to UP_RIGHT and move one column right.
If going UP_RIGHT, decrease r (move up one row) and increase c (move right one column).
If reaching the top row, flip to DOWN and move one column left.
Decrement count to track remaining characters.
Building the result string:

After processing all characters, iterate through the table row by row.
For each non-null character in the row, append it to the s_result string.
This effectively combines the characters in row order, preserving the zig-zag pattern.
Return result:

The final s_result string contains the original string characters arranged in the desired zig-zag layout across the specified number of rows.
