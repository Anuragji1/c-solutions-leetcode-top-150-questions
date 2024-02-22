**Course Schedule II**

Problem Statement 94) There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.

------------------------------------------------------------------------------------------------------
SOLUTION = int cmpfunc(const void* a, const void* b){
    int* arr1 = *(int**)a;
    int* arr2 = *(int**)b;
    
    return arr1[1] - arr2[1];
}

int BTS(int** arr, int arrSize, int val){
    int left = 0, right = arrSize-1;
    int mid;
    while(left < right){
        mid = left + (right - left)/2 ;
        if(arr[mid][1] >= val)
            right = mid;
        else
            left = mid + 1;
    }
    if(arr[left][1] == val)
        return left;
    else
        return -1;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
    int* prereqCn = calloc(numCourses , sizeof(int));
    for(int i = 0; i < prerequisitesSize; i++){
        prereqCn[ prerequisites[i][0] ]++;
    }
    //depend test case : queue can be smaller 
    int* queue = malloc(1000 * sizeof(int));
    int Qidx  = 0;
    for(int i = 0; i < numCourses; i++){
        if(prereqCn[i] == 0){
            queue[Qidx] = i;
            Qidx++;
        }
    }
    if(prerequisitesSize > 0)
        qsort(prerequisites, prerequisitesSize, sizeof(int*), cmpfunc);
    int* ans = malloc( numCourses * sizeof(int)) ;
    int andIdx = 0;
    while(Qidx){
        Qidx--;
        int val = queue[Qidx];
        ans[andIdx] = val;
        andIdx++;
        if(prerequisitesSize > 0){
            int k = BTS(prerequisites, prerequisitesSize, val);
            if(k != -1){
                while(k < prerequisitesSize && prerequisites[k][1] == val){
                    prereqCn[ prerequisites[k][0] ]--;
                    if( prereqCn[ prerequisites[k][0] ] == 0  ){
                        queue[Qidx] = prerequisites[k][0] ;
                        Qidx++;  
                    }
                    k++;
                }
            }
        }
    }
    //if collision happen, then no ans
    if(andIdx != numCourses){
        *returnSize = 0;
        free(ans);
        return NULL;
    }
    else
        *returnSize = numCourses;
    return ans;
}

--------Explanation :-
Functionality:

This code implements a function findOrder that determines a possible order to finish all courses in a system given a list of prerequisite relationships. It uses a topological sort algorithm based on Breadth-First Search (BFS) to detect cycles in the course dependency graph.

Key Steps:

Initialization:

Create an array prereqCn to store the in-degree (number of prerequisites) for each course (0-based indexing).
Fill prereqCn by iterating through prerequisites:
For each prerequisite relationship [course_j, course_i], increment the in-degree of course_i (as it depends on course_j).
Create a queue queue initially empty.
Add all courses with zero in-degree (no prerequisites) to the queue.
Topological Sort:

If there are prerequisites (prerequisitesSize > 0):
Sort the prerequisites array using qsort based on the "to" course (index 1), making the binary search in step 4 more efficient.
Create an empty array ans to store the course completion order.
Set an index andIdx to track the position in ans for completed courses.
While the queue is not empty:
Dequeue a course val from the queue.
Add val to the ans array at the current andIdx position.
Increment andIdx.
If there are prerequisites:
Use binary search with BTS to find the first prerequisite index k for val in the sorted prerequisites array.
If k is not found (-1), all prerequisites for val have been visited (handled correctly by sorting).
Otherwise, iterate through prerequisites starting from k until the "to" course changes:
Decrease the in-degree of the dependent course (prereqCn[prerequisites[k][0]]).
If the in-degree becomes zero, add the dependent course to the queue for future processing.
Result:

If all courses have been completed (andIdx == numCourses), there are no cycles, and the ans array represents a valid completion order. Set returnSize and return ans.
Otherwise, a cycle exists in the dependency graph, and it's impossible to finish all courses. Set returnSize to 0, free ans, and return NULL.
Key Points:

The code effectively uses BFS to perform a topological sort of the course dependency graph.
Binary search (BTS) optimizes the process of finding relevant prerequisites for a course.
Sorting prerequisites by the "to" course improves binary search efficiency.
The code handles cases where a course has no prerequisites or all its prerequisites have been visited.
It detects cycles and returns NULL if a valid completion order is not possible.
