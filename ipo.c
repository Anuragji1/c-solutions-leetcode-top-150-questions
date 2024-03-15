**IPO**

Problem Statement 114) Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

 

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6
 

Constraints:

1 <= k <= 105
0 <= w <= 109
n == profits.length
n == capital.length
1 <= n <= 105
0 <= profits[i] <= 104
0 <= capital[i] <= 109

------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int heap_cap_add(int* cap, int* heap, int *element_num, int element)
{
	int cur_num = 0;
	int tmp = 0;
    int n_idx = 0;
	
	*element_num = *element_num + 1;
	cur_num = *element_num;
	heap[cur_num] = element;
	
	while (1) {
		if (cur_num == 1) {
			break;
		}
        n_idx = cur_num/2;
		if (cap[heap[cur_num]] < cap[heap[n_idx]]) {
			tmp = heap[cur_num];
			heap[cur_num] = heap[n_idx];
			heap[n_idx] = tmp;
			cur_num = n_idx;
		} else {
			break;
		}
	}
	
	return 0;
}

int heap_cap_pop(int* cap, int* heap, int *element_num, int *pop_element)
{
	int cur_idx = 1;
	int cur_total = 0;
	int tmp = 0;
	int min_idx = 0;
    int i = 0;
    int n_idx = 0;
	
	if (*element_num == 0) {
        *pop_element = 0;
        return 0;
    }

	*pop_element = heap[1];
	heap[1] = heap[*element_num];
	*element_num = *element_num - 1;
	cur_total = *element_num;
	while (1) {
        n_idx = cur_idx*2;
		if (n_idx > cur_total) {
			break;
		}
        if (n_idx == cur_total) {
            if (cap[heap[cur_idx]] > cap[heap[n_idx]]) {
                min_idx = n_idx;
                tmp = heap[cur_idx];
                heap[cur_idx] = heap[min_idx];
                heap[min_idx] = tmp;
                cur_idx = min_idx; 
            } 
            break;
            
        }
		
		if (cap[heap[cur_idx]] > cap[heap[n_idx]] || cap[heap[cur_idx]] > cap[heap[n_idx + 1]]) {
			min_idx = (cap[heap[n_idx + 1]] < cap[heap[n_idx]])?n_idx + 1:n_idx;
			tmp = heap[cur_idx];
			heap[cur_idx] = heap[min_idx];
			heap[min_idx] = tmp;
			cur_idx = min_idx;
		} else {
            break;
        }
	}

	return 0;
}

int heap_add(int* heap, int *element_num, int element)
{
	int cur_num = 0;
	int tmp = 0;
    int n_idx = 0;
	
	*element_num = *element_num + 1;
	cur_num = *element_num;
	heap[cur_num] = element;
	
	while (1) {
		if (cur_num == 1) {
			break;
		}
        n_idx = cur_num/2;
		if (heap[cur_num] > heap[n_idx]) {
			tmp = heap[cur_num];
			heap[cur_num] = heap[n_idx];
			heap[n_idx] = tmp;
			cur_num = n_idx;
		} else {
			break;
		}
	}
	
	return 0;
}

int heap_pop(int* heap, int *element_num, int *pop_element)
{
	int cur_idx = 1;
	int cur_total = 0;
	int tmp = 0;
	int max_idx = 0;
    int i = 0;
    int n_idx = 0;
	
	if (*element_num == 0) {
        *pop_element = 0;
        return 0;
    }

	*pop_element = heap[1];
	heap[1] = heap[*element_num];
	*element_num = *element_num - 1;
	cur_total = *element_num;
	while (1) {
        n_idx = cur_idx*2;
		if (n_idx > cur_total) {
			break;
		}
        if (n_idx == cur_total) {
            if (heap[cur_idx] < heap[n_idx]) {
                max_idx = n_idx;
                tmp = heap[cur_idx];
                heap[cur_idx] = heap[max_idx];
                heap[max_idx] = tmp;
                cur_idx = max_idx; 
            } 
            break;
            
        }
		
		if (heap[cur_idx] < heap[n_idx] || heap[cur_idx] < heap[n_idx + 1]) {
			max_idx = (heap[n_idx + 1] > heap[n_idx])?n_idx + 1:n_idx;
			tmp = heap[cur_idx];
			heap[cur_idx] = heap[max_idx];
			heap[max_idx] = tmp;
			cur_idx = max_idx;
		} else {
            break;
        }
	}

	return 0;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize){
    int i = 0, j = 0;
    int table[100001] = {0};
    int cap_table[100001] = {0};
    int table_num = 0;
    int cap_table_num = 0;
    int output = 0;
    int cur_w = w;
    int tmp = 0;
    int tmp_j = 0;
    int tmp_max = 0;
    int l = 0;
 

    // sort
    for (i = 0; i < profitsSize; i++) {
        heap_cap_add(capital, cap_table, &cap_table_num, i);
    }


    for (i = 0; i < k; i++) {
        while (1) {
            if (capital[cap_table[1]] > cur_w || cap_table_num == 0) {
                break;
            }
            heap_cap_pop(capital, cap_table, &cap_table_num, &tmp);
            heap_add(table, &table_num, profits[tmp]);
        }
        heap_pop(table, &table_num, &tmp);
        cur_w += tmp;
    }

    output = cur_w;

    return output;
}

------Explanation :- 
Data Structures:

profits: Array of size profitsSize storing the profit associated with each project.
capital: Array of size capitalSize storing the capital required to start each project.
table: Heap (assumed to be a max-heap) used to store the profits of achievable projects based on current capital.
cap_table: Heap (assumed to be a min-heap based on capital requirement) used to store indices of projects sorted by their capital requirements.
Helper Functions (not shown in detail):

heap_cap_add (assumed): Adds an element to the cap_table heap while maintaining the min-heap property based on capital requirement.
heap_cap_pop (assumed): Removes and returns the element with the minimum capital requirement (root) from the cap_table heap while maintaining the min-heap property.
heap_add (assumed): Adds an element to the table heap (assumed max-heap) while maintaining the max-heap property based on profit.
heap_pop (assumed): Removes and returns the element with the maximum profit (root) from the table heap (assumed max-heap) while maintaining the max-heap property.
Algorithm:

Sort Projects by Capital Requirement (implicitly):

The code utilizes the heap_cap_add function (assumed) to add project indices to the cap_table heap. Since cap_table is assumed to be a min-heap, this implicitly sorts the projects based on their capital requirement (indices with lower capital requirement are added to the heap first).
Iterate for k Projects:

The loop iterates k times, representing selecting up to k projects.
In each iteration:
While the capital (cur_w) is sufficient and there are projects in the cap_table heap:
Remove the project with the minimum capital requirement (index from cap_table) using heap_cap_pop.
Add the profit of that project to the table heap (assumed max-heap) using heap_add.
Remove the project with the maximum profit (from table) using heap_pop. This effectively selects the highest profit achievable with the current capital.
Update the current capital cur_w by adding the selected project's profit.
Return Maximum Capital:

After iterating k times, cur_w will hold the maximum total profit achievable using at most k projects.
