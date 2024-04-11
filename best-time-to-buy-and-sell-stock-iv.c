**Best Time to Buy and Sell Stock IV**

Problem Statement 149) You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

--------------------------------------------------------------------------------------------------------------
SOLUTION = int max(int a, int b)
{
	if (a > b) 
	{
		return a;    
	}
	return b;
}

int maxProfit(int k, int* prices, int n)
{
	if (n < 2) 
	{
		return 0;
	}
	int sold[n][k + 1];
	int hold[n][k + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= k; j++)
		{
			sold[i][j] = -10000;
			hold[i][j] = -10000;
		}
	sold[0][0] = 0;
	hold[0][0] = -(*prices);

	for (int i = 1; i < n; i++)
	{
		hold[i][0] = max(-prices[i], hold[i - 1][0]);
		for (int j = 1; j <= k; j++)
		{
			hold[i][j] = max(hold[i - 1][j], sold[i - 1][j] - prices[i]);
			sold[i][j] = max(sold[i - 1][j], hold[i - 1][j - 1] + prices[i]);
		}
	}
	int res = 0;
	for (int i = 0; i <= k; i++) {
		res = max(res, sold[n - 1][i]);
	}
	return res;
}

----Explanation :-
Helper function max:

A helper function max(a, b) is included to find the maximum of two integer values a and b. This is used throughout the code for comparisons.
Base Case (n < 2):

The main maxProfit function first checks if the number of prices (n) is less than 2. If there are less than 2 prices (no transaction possible), the function returns 0, indicating no profit.
DP Arrays and Initialization:

The code declares two 2D integer arrays:

sold[n][k+1]: Stores the maximum profit obtained by selling a stock on day i (0-based index) after having a total of j (0 to k) transactions. It's initialized with a very negative value (-10000) to represent an invalid state initially.
hold[n][k+1]: Stores the maximum profit obtained by holding a stock on day i after having a total of j (0 to k) transactions. It's also initialized with -10000.
An important initialization to note is sold[0][0] = 0, which represents the profit after 0 transactions on day 0 (no buying or selling yet). hold[0][0] = -prices[0] represents holding a stock bought on day 0 (initial profit is negative by the purchase price).

Iterative DP Calculations:

It uses nested for loops to iteratively fill the sold and hold arrays:

The outer loop (i) iterates from 1 to n-1 (excluding the first day as there can't be a sell on day 0).
The inner loop (j) iterates from 1 to k (considering up to k transactions).
Holding Stock:

hold[i][j]: The code calculates the maximum profit possible by holding a stock on day i with j transactions. It considers two options:
Hold the stock from the previous day (hold[i-1][j]).
Sell the stock bought on the previous day (if any transactions left) and hold cash (sold[i-1][j-1] - prices[i]). The profit here is the previous sell profit minus the current buy price.
The maximum of these two options is stored in hold[i][j].
Selling Stock:

sold[i][j]: The code calculates the maximum profit possible by selling a stock on day i with j transactions. It considers two options:
Keep holding the stock from the previous day (hold[i-1][j]).
Sell the stock bought earlier (if any transactions done) and update the sell value (hold[i-1][j-1] + prices[i]). The profit here is the previous holding profit plus the current sell price.
The maximum of these two options is stored in sold[i][j].
Finding Maximum Profit:

After iterating through all days and transactions, the code needs to find the overall maximum profit achievable. It uses another loop (i) to iterate from 0 to k (transaction counts). It compares the sold value on the last day (n-1) for each transaction count (j) with the current res variable (initialized to 0). The maximum of these comparisons is stored in res.
Return the Maximum Profit:

Finally, the function returns the value of res, which represents the maximum profit achievable by buying and selling the stock any number of times up to k transactions.
