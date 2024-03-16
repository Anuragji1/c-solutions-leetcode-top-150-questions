**Find K Pairs with Smallest Sums**

Problem Statement 115) You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length

--------------------------------------------------------------------------------------------------------------------------------
SOLUTION = /**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
long long countLessEqualItems(int val, int* nums1, int n1, int* nums2, int n2){
    long long ans = 0 ;
    for(int i = 0; i < n1; i++){
        int k = val - nums1[i] ;
        int l = 0, r = n2-1 ;
        if(nums2[0] > k)
            break ;
        while(l < r){
            int mid = r - (r-l)/2 ;
            if(nums2[mid] > k)
                r = mid - 1 ;
            else
                l = mid ;
        }
        ans += (l + 1) ;
    }
    return ans ;
}
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    int n1 = nums1Size ;
    int n2 = nums2Size ;
    int lower = nums1[0] + nums2[0] ;
    int upper = nums1[n1-1] + nums2[n2-1] ;

    while(lower < upper){
        int mid = lower + (upper - lower) / 2 ;
        long long t = countLessEqualItems(mid, nums1, n1, nums2, n2) ;
        if(t >= k)
            upper = mid ;
        else
            lower = mid + 1 ;
    }

    int** ans = malloc(k * sizeof(int*)) ;
    for(int i = 0; i < k; i++){
        ans[i] = malloc(2 * sizeof(int) );
    }
    int** tmp = malloc(k * sizeof(int*)) ;
    int a_idx = 0, t_idx = 0 ;
    for(int i = 0; i < n1; i++){
        for(int j = 0;  j < n2; j++){
            int sum = nums1[i] + nums2[j] ;
            if(sum < lower){
                ans[a_idx][0] = nums1[i] ;
                ans[a_idx][1] = nums2[j] ;
                a_idx++ ;
            }
            else if(sum == lower){
                if(t_idx == k)
                    break ;
                tmp[t_idx] = malloc(2 * sizeof(int)) ;
                tmp[t_idx][0] = nums1[i] ;
                tmp[t_idx][1] = nums2[j] ;
                t_idx++ ;
            }
            else 
                break ;
        }
    }

    int a = 0 ;

    if(a_idx < k){
        for(int i = a_idx; i < k; i++){
            if(a == t_idx)
                break ;
            ans[a_idx][0] = tmp[a][0] ;
            ans[a_idx][1] = tmp[a][1] ;
            a++ ;
            a_idx++ ;
        }
    }

    *returnSize = a_idx ;
    *returnColumnSizes = malloc(a_idx * sizeof(int)) ;
    
    for(int i = 0; i < a_idx; i++){
        returnColumnSizes[0][i] = 2 ;
    }
    for(int i = 0; i < t_idx; i++){
        free(tmp[i]) ;
    }
    free(tmp) ;
    return ans ;
}

----------Explanation :- /**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
long long countLessEqualItems(int val, int* nums1, int n1, int* nums2, int n2){
    long long ans = 0 ;
    for(int i = 0; i < n1; i++){
        int k = val - nums1[i] ;
        int l = 0, r = n2-1 ;
        if(nums2[0] > k)
            break ;
        while(l < r){
            int mid = r - (r-l)/2 ;
            if(nums2[mid] > k)
                r = mid - 1 ;
            else
                l = mid ;
        }
        ans += (l + 1) ;
    }
    return ans ;
}
int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes){
    int n1 = nums1Size ;
    int n2 = nums2Size ;
    int lower = nums1[0] + nums2[0] ;
    int upper = nums1[n1-1] + nums2[n2-1] ;

    while(lower < upper){
        int mid = lower + (upper - lower) / 2 ;
        long long t = countLessEqualItems(mid, nums1, n1, nums2, n2) ;
        if(t >= k)
            upper = mid ;
        else
            lower = mid + 1 ;
    }

    int** ans = malloc(k * sizeof(int*)) ;
    for(int i = 0; i < k; i++){
        ans[i] = malloc(2 * sizeof(int) );
    }
    int** tmp = malloc(k * sizeof(int*)) ;
    int a_idx = 0, t_idx = 0 ;
    for(int i = 0; i < n1; i++){
        for(int j = 0;  j < n2; j++){
            int sum = nums1[i] + nums2[j] ;
            if(sum < lower){
                ans[a_idx][0] = nums1[i] ;
                ans[a_idx][1] = nums2[j] ;
                a_idx++ ;
            }
            else if(sum == lower){
                if(t_idx == k)
                    break ;
                tmp[t_idx] = malloc(2 * sizeof(int)) ;
                tmp[t_idx][0] = nums1[i] ;
                tmp[t_idx][1] = nums2[j] ;
                t_idx++ ;
            }
            else 
                break ;
        }
    }

    int a = 0 ;

    if(a_idx < k){
        for(int i = a_idx; i < k; i++){
            if(a == t_idx)
                break ;
            ans[a_idx][0] = tmp[a][0] ;
            ans[a_idx][1] = tmp[a][1] ;
            a++ ;
            a_idx++ ;
        }
    }

    *returnSize = a_idx ;
    *returnColumnSizes = malloc(a_idx * sizeof(int)) ;
    
    for(int i = 0; i < a_idx; i++){
        returnColumnSizes[0][i] = 2 ;
    }
    for(int i = 0; i < t_idx; i++){
        free(tmp[i]) ;
    }
    free(tmp) ;
    return ans ;
}
