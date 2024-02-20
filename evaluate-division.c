**Evaluate Division**

Problem Statement 92) You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.

--------------------------------------------------------------------------------------------------------------------
SOLUTION = #define MAX_ELEMENTS 40
int map_str(char* strs[MAX_ELEMENTS], char *s, int num){
    int ii;
    for (ii=0; ii<num; ii++){
        if (!strcmp(strs[ii],s))
            return ii+1;
    }
    return 0;
}


int findDJ (int *rt, double wt[][MAX_ELEMENTS], int x){
    int rx = rt[x];
    if (rx == x){
        return x;
    }
    rt[x] = findDJ(rt, wt, rx);
    if (rt[x] != rx) {
        wt[x][rt[x]] = wt[x][rx] * wt[rx][rt[x]];
        wt[rt[x]][x] = 1/(wt[x][rt[x]]);
//        printf("x %d rx %d, rt[x] %d, wt[x][rt[x]] %f, wt[x][rx] %f  wt[rx][rt[x]] %f \n", x, rx, rt[x], wt[x][rt[x]], wt[x][rx],  wt[rx][rt[x]]);
    }
    return (rt[x]);
}

void unionDJ(int *rt, int *rnk, double wt[][MAX_ELEMENTS], double w, int x, int y){
    int rx, ry;
    rx = findDJ(rt, wt, x);
    ry = findDJ(rt, wt, y);
    wt[x][y] = w;
    wt[y][x] = 1/w;
    if (rx == ry) return;
	/* calculate the weight of wt[rx][ry] */
    wt[rx][ry] = wt[rx][x] * wt[y][ry] *wt[x][y];
    wt[ry][rx] = 1/(wt[rx][ry]);
    if (rnk[rx] > rnk[ry]){
        rt[ry] = rx;
    }else if (rnk[ry] > rnk[rx]){
        rt[rx] = ry;
    }else{
        rt[ry] = rx;
        rnk[rx] += 1;
    }
//    printf("x %d y %d rx %d, ry %d rt[rx] %d rt[ry] %d ", x, y, rx, ry, rt[rx], rt[ry]);
//    printf("wt[%d][%d] %f wt[%d][%d] %f wt[rx][x] %f , w %f\n", rx, ry, wt[rx][ry], ry, rx,wt[ry][rx],  wt[rx][x], w);
    return;
}

double* calcEquation(char *** equations, int equationsSize, int* equationsColSize, double* values, int valuesSize, char *** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int num_strs=0;
    char *strs[MAX_ELEMENTS];
    int rt[MAX_ELEMENTS];
    char *s;
    int map_id1, map_id2;
    double wt[MAX_ELEMENTS][MAX_ELEMENTS];
    {
        int rnk[MAX_ELEMENTS];
        for (int ii=0; ii< MAX_ELEMENTS; ii++){
                for (int jj=0; jj< MAX_ELEMENTS; jj++)
                    wt[ii][jj] = 1.0;
                rt[ii]  =ii;
                rnk[ii] = 1;
        }
        for (int ii=0; ii< equationsSize; ii++){
            /* get each string and mapped id of string*/
            s =  equations[ii][0];
            if (!(map_id1 = map_str(strs, s, num_strs))){
                strs[num_strs] = s;
                map_id1 = num_strs;
                num_strs++;
            }else  map_id1--;
            s =  equations[ii][1];
            if (!(map_id2 = map_str(strs, s, num_strs))){
                strs[num_strs] = s;
                map_id2 = num_strs;
                num_strs++;
            }else map_id2--;
    //        printf(" id1 %d, y %s  snum %d id2 %d num_strs %d\n", map_id1, s, snum,map_id2, num_strs);
	
			/* link these vertices and calculate the corresponding weights */
            unionDJ(rt, rnk, wt, values[ii], map_id1, map_id2);
        }
    }
	
	/* allocation for output */
    double *res = (double *) malloc(sizeof(double) * queriesSize);

    for (int ii=0; ii<queriesSize; ii++){
	    /* get the mapped id strings, if not there set result as -1 */
        s = queries[ii][0];
        if (!(map_id1 = map_str(strs, s, num_strs))){
            res[ii] = -1;
            continue;
        }else map_id1--;
        s = queries[ii][1];
        if (!(map_id2 = map_str(strs, s, num_strs))){
            res[ii] = -1;
            continue;
        }else map_id2--;
		
		/* if query has same strings as "a"/"a", set to 1 */
        if (map_id1 == map_id2){
            res[ii] = 1;
        }
//    printf("qii %d , x %s id1 %d, y %s, id2 %d, wt %f\n",ii,queries[ii][0], map_id1, queries[ii][1], map_id2,  wt[map_id1][map_id2] );
        /* While doing union some weights gets calculated ,
		   eg, (a, b, w1), (b, c, w2), (c, d, w3) ==>
		   weigths corresponding to a,b ; b,c; a,c; c,d;a,d gets calculated in unionDJ func */
        else if (wt[map_id1][map_id2] != 1.0)
            res[ii] = wt[map_id1][map_id2];
        else {
			/* there are cases where some weights will not be calculated 
		   eg, (a, b, w1), (b, c, w2), (c, d, w3) ==>
		   weigths corresponding to b,d will not get caluculated.
		    so check if these are linked and update weights*/
            int rx =  findDJ(rt, wt, map_id1);
            int ry = findDJ (rt, wt, map_id2);
            if (rx == ry){
                res[ii] = wt[map_id1][rx] * wt[rx][map_id2];
            } else
                res[ii] = -1.0;
        }
    }
    *returnSize = queriesSize;
    return res;
}

-----------------Explanation :-
Functionality:

This code implements a function calcEquation that solves equations and queries involving variables represented by strings and their values. It uses a Disjoint-Set Union (DSU) data structure and path compression to efficiently manage unions and find weights between variables.

Key Steps:

Initialization:

Creates two arrays:
strs: Stores unique strings encountered in equations and queries (up to a limit of MAX_ELEMENTS).
rt: Represents the parent/root of each string in the DSU structure.
Initializes rt array with each element pointing to itself (indicating individual sets).
Creates a 2D array wt to store calculated weights between pairs of strings. Initializes all weights to 1.0.
Processing Equations:

Iterates through each equation (equations):
For each equation a / b = w:
Maps a and b to their corresponding indices in strs using map_str.
If either string is not found, adds it to strs and updates its index.
Performs a union operation in the DSU using unionDJ:
Finds the roots (rx and ry) of a and b using findDJ.
If they belong to the same set, skip (already linked).
Otherwise, update the rt array and calculate the corresponding weight between them, storing it in wt[a][b] and wt[b][a].
Adjust weight calculation based on path compression updates in findDJ.
Processing Queries:

Allocates memory for the output array res to store answers for each query.
Iterates through each query (queries):
Maps x and y to their corresponding indices in strs using map_str.
If either string is not found, set the corresponding result in res to -1 (undefined).
If x and y are the same string, set the result to 1 (equivalent).
Otherwise:
Find the roots (rx and ry) of x and y using findDJ.
If they belong to different sets, the equation is undefined; set the result to -1.
Otherwise, the result is the weight stored in wt[x][y] (or wt[y][x] due to symmetry), considering path compression adjustments.
Return Result:

Sets returnSize to the number of queries (queriesSize).
Returns the calculated results array res.
Key Points:

The code efficiently handles equations and queries involving string variables using DSU.
The findDJ function implements path compression for optimal performance.
Weights are calculated and stored in the wt array during DSU operations.
The code handles different cases like strings not found, equivalent expressions, and undefined equations.
