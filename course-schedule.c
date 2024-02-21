**Course Schedule**

Problem Statement 93) There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

---------------------------------------------------------------------------------------------------------------------------------
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

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
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

    int CourseSeq = 0;
    while(Qidx){
        Qidx--;
        int val = queue[Qidx];
        CourseSeq++;
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
    if(CourseSeq != numCourses){
        return false;
    }
    else
        return true;
}

----Explanation :-
Functionality:

This code implements a function canFinish that determines whether it's possible to complete all courses in a system given a list of prerequisite relationships. It uses a topological sort algorithm based on Breadth-First Search (BFS) to detect cycles in the course dependency graph.

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
While the queue is not empty:
Dequeue a course val from the queue.
Increment the completed course count (CourseSeq).
If there are prerequisites:
Use binary search with BTS to find the first prerequisite index k for val in the sorted prerequisites array.
If k is not found (-1), all prerequisites for val have been visited (handled correctly by sorting).
Otherwise, iterate through prerequisites starting from k until the "to" course changes:
Decrease the in-degree of the dependent course (prereqCn[prerequisites[k][0]]).
If the in-degree becomes zero, add the dependent course to the queue for future processing.
Result:

If all courses have been completed (CourseSeq == numCourses), there are no cycles, and it's possible to finish all courses. Return true.
Otherwise, a cycle exists in the dependency graph, and it's impossible to finish all courses. Return false.
