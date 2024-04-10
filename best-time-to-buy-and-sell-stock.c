**Best Time to Buy and Sell Stock**

Problem Statement 148) You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

---------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int maxProfit(int* prices, int pricesSize) {
    int buy1 = INT_MIN, buy2 = INT_MIN;
    int sell1 = 0, sell2 = 0;

    for (int i = 0; i < pricesSize; i++) {
        // Update buy prices for first and second transactions
        buy1 = fmax(buy1, -prices[i]);
        buy2 = fmax(buy2, sell1 - prices[i]);

        // Update sell prices for first and second transactions
        sell1 = fmax(sell1, buy1 + prices[i]);
        sell2 = fmax(sell2, buy2 + prices[i]);
    }

    return sell2; // Maximum profit is from the second sell
}

----Explanation :-
Initialization:

The code declares four integer variables:
buy1: Tracks the minimum buying price for the first transaction (can be negative INT_MIN to allow buying at any price).
buy2: Tracks the minimum buying price for the second transaction (can be negative INT_MIN to allow buying at any price after the first sell).
sell1: Tracks the maximum profit obtained so far after the first sell (initialized to 0).
sell2: Tracks the maximum profit obtained so far after the second sell (initialized to 0).
Iterating Through Prices:

It uses a for loop to iterate through the prices array (pricesSize times). For each day (i), it considers buying and selling possibilities:
Updating Buying Prices:

buy1: The minimum buying price for the first transaction is updated using fmax(buy1, -prices[i]). This ensures buy1 always holds the lowest buying price encountered so far (including negative values to allow buying at any price).
buy2: The minimum buying price for the second transaction is trickier. It's updated using fmax(buy2, sell1 - prices[i]). Here, sell1 - prices[i] represents the potential profit if we sell the stock bought for buy1 today (at price prices[i]). So, buy2 is updated to the lower of its current value and the potential profit from selling the first buy followed by buying again at prices[i]. This allows buying again at a potentially lower price for the second transaction.
Updating Selling Prices:

sell1: The maximum profit after the first sell is updated using fmax(sell1, buy1 + prices[i]). This calculates the profit if we sell the stock bought for buy1 today (at price prices[i]). sell1 is always updated to the maximum profit encountered so far after the first sell.
sell2: The maximum profit after the second sell is updated using fmax(sell2, buy2 + prices[i]). This calculates the profit if we sell the stock bought for buy2 today (at price prices[i]). sell2 is always updated to the maximum profit encountered so far after the second sell.
