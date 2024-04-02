**Coin Change**

Problem Statement 132) You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

-----------------------------------------------------------------------------------------------
SOLUTION = int coinChange(int* coins, int len, int amount){
    if(amount==0)return 0;
    int minCoins[amount+1];
    minCoins[0]=0;
    for(int i=1;i<=amount;i++)minCoins[i]=INT_MAX;
    for(int i=1;i<=amount;i++){
        for(int j=0;j<len;j++){
            if(coins[j]<=i){
                int temp=minCoins[i-coins[j]];
                if(temp!=INT_MAX && temp+1<minCoins[i])
                    minCoins[i]=temp+1;
            }
        }
    }
    if(minCoins[amount]==INT_MAX)return -1;
    return minCoins[amount];
}

----Explanation :-
Base Case:

The code starts by checking for the base case: If the amount is 0, it means no coins are needed, so it returns 0.
minCoins Array:

It declares an integer array minCoins of size amount + 1. This array will store the minimum number of coins required to make every amount from 0 up to the target amount.
The first element minCoins[0] is initialized to 0, representing the minimum number of coins needed to make 0 amount (which is 0).
Dynamic Programming Loop:

It uses nested for loops to iteratively build the solution in the minCoins array:
The outer loop (i) iterates from 1 to amount (representing all possible target amounts).
The inner loop (j) iterates from 0 to len - 1 (iterating through all coin denominations in the coins array).
Subproblem Consideration:

Inside the inner loop, it checks if the current coin denomination (coins[j]) is less than or equal to the current target amount (i). This ensures that we only consider coins that can contribute to making the target amount.
If the condition is true:
It calculates a temporary value temp by looking up the minimum number of coins required to make an amount i - coins[j] (which is the remaining amount after potentially using the current coin). This value is retrieved from the minCoins array at index i - coins[j].
It checks if temp is not INT_MAX (indicating an unreachable amount) and if temp + 1 is less than the current value in minCoins[i]. This check ensures that we only update minCoins[i] if a new minimum is found.
If both conditions are met, it updates minCoins[i] to temp + 1. This means that using the current coin (coins[j]) once and then making the remaining amount (i - coins[j]) with the minimum coins possible (as stored in temp) leads to a minimum total of temp + 1 coins for the target amount i.
Handling Unreachable Amounts:

After the nested loops complete, if the value in minCoins[amount] (representing the minimum number of coins for the target amount) is still INT_MAX, it signifies that there is no combination of coins that can make the target amount. In this case, the function returns -1.
Return the Result:

If a valid minimum number of coins is found, the function returns the value stored in minCoins[amount], which represents the minimum number of coins required to make the target amount amount.
