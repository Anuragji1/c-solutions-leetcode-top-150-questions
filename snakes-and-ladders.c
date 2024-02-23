**Snakes and Ladders**

Problem Statement 95) You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

 

Example 1:


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1
 

Constraints:

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 do not have any ladders or snakes.

----------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = /* Solution inspired by https://leetcode.com/problems/snakes-and-ladders/solutions/2622634/self-explanatory-c-bfs/
   on how to calculate the destination (findCoord), and by trial and error of when to take the ladder or snake or not
*/

// Global variables so you don't need to pass them as arguments on functions
bool* vis; //Array to keep track of visited positions
int* dist; //Arreay to keep distances of reached positions
int* queue; //Queue to do a BF
int size; //Size of matrix

// All these are initialized bellow

// Find which row and col is the target place
void findCoord(int target, int n, int* x, int* y){
    int row = (target - 1)/n;
    int col = (target - 1)%n;

    *x = n - 1 - row;
    *y = row%2==0 ? col : n - 1 - col; 
}

// BF (smallest path on no weight graph)
void BF(int** board, int n, int m, int or){
    // Init vars
    int cur, first = 0, last = 0, x, y, steps;
    vis[or] = true;
    queue[last++] = or;
    // While there's spots we can reach
    while(first!=last){
        cur = queue[first++];
        findCoord(cur, n, &x, &y);
        steps = 1;
        // Check if we can reach the six closet spots
        while(steps<=6){
            // If we reach the last one, theres no need to keep going
            if(cur+steps==size){ 
                dist[size] = dist[cur]+1;
                return;
            }
            findCoord(cur+steps, n, &x, &y);
            // Check if we are on a ladder or snake
            if(board[x][y]!=-1){
                // if we already visited the position were the ladder or snake is going we should just take another path
                if(vis[board[x][y]]){
                    steps++;
                    continue;    
                }
                // else we should continue on the path of the ladder or snake to see where it goes
                dist[board[x][y]] = dist[cur] + 1;
                queue[last++] = board[x][y];
                vis[board[x][y]] = true;
                if(board[x][y]==size) return;
            }
            // If it's not a ladder or snake and we haven't visited the position we should add it to the queue and see where it leads
            else if(!vis[cur+steps]){
                queue[last++] = cur+steps;
                vis[cur+steps] = true;
                dist[cur+steps] = dist[cur]+1;
            } 
            steps++;
        }
    }
}

int snakesAndLadders(int** board, int boardSize, int* boardColSize){
    //Variables initialization
    size = boardSize*boardSize;
    vis = calloc(size+1, sizeof(bool));
    dist = calloc(size+1, sizeof(int));
    queue = calloc(size, sizeof(int));
    BF(board, boardSize, *boardColSize, 1);

    //If distance on last position is 0 it means we haven't reach that position
    //If board was 1x1 this would give us a wrong answer, but since the restrictions say it's at least a 2x2 board, we can do this
    //In a 1x1 board we would simply return 0, since the begin == end
    int ans = dist[size]==0?-1:dist[size];
    
    // We don't want memory leaks :)
    free(vis);
    free(dist);
    free(queue);
    return ans;
}

--------Explanation :-
Functionality:

This code implements the snakesAndLadders function, which calculates the minimum number of dice throws required to reach the end position in a Snakes and Ladders game represented by a board. It uses a Breadth-First Search (BFS) algorithm to explore possible paths and keep track of the shortest distance reached.

Key Steps:

Initialization:

Set size to the total number of squares on the board (e.g., boardSize * boardSize).
Allocate memory for:
vis: Boolean array to track visited positions (size size + 1).
dist: Integer array to store distances reached (size size + 1).
queue: Integer queue to store positions to explore (size size).
Initialize vis and dist to 0.
BFS Search:

Call BF function with the board, board size, number of columns, and starting position (1).
The BF function performs the actual BFS exploration:
Marks the starting position as visited and adds it to the queue.
While the queue is not empty:
Dequeue the current position cur.
Find its row and column coordinates.
Explore all possible moves (up to 6 steps).
For each move:
Check if it's the last position (cur + steps == size). If so, update the distance in dist[size] and return.
Check if the new position is on a ladder or snake using board[x][y].
If the new position is already visited (ladder/snake leads to a loop), skip it.
Otherwise, update distance in dist[board[x][y]], mark it as visited, and add it to the queue.
If the new position is not on a ladder/snake and not visited, add it to the queue and update its distance.
Result:

If dist[size] is 0, it means no path was found. Return -1.
Otherwise, return the distance stored in dist[size] as the minimum number of moves.
Memory Management:

Free the allocated memory for vis, dist, and queue.
Key Points:

The code uses BFS efficiently to explore possible paths and prioritize shorter ones.
It handles ladders and snakes by checking the corresponding positions in the board array.
It avoids infinite loops by skipping already visited positions on ladders/snakes.
The code is well-structured and includes comments for better understanding.
