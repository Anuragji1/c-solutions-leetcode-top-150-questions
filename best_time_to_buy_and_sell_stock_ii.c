**Best Time to Buy and Sell Stock II**

Problem Statement 8) You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int maxProfit(int* prices, int pricesSize) {
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) {  // Check for potential profit
            maxProfit += prices[i] - prices[i - 1];  // Accumulate profit
        }
    }

    return maxProfit;
}

----------------------------Explanation :-
Purpose:

The code implements a function named maxProfit() that calculates the maximum profit that can be achieved by buying and selling a stock multiple times, given a list of daily stock prices. It assumes no transaction fees.
Key Steps:

Initialization:

maxProfit is initialized to 0 to track the accumulated profit.
Iteration Through Prices with Profit Accumulation:

The code iterates through the prices array, starting from the second price:
It checks if the current price is higher than the previous price.
If so, it means a profitable sale can be made, so the difference between the current and previous price is added to maxProfit.
This process effectively captures all possible "upward slopes" in the price chart, representing profitable trades.
Return Maximum Profit:

After iterating through all prices, the function returns the total accumulated maxProfit value, representing the maximum achievable profit through multiple trades.
Time and Space Complexity:

Time Complexity: O(n), where n is the number of prices in the array. It performs a single linear pass through the array.
Space Complexity: O(1), as it uses only a constant amount of extra space for variables, regardless of the input size.
Key Assumption:

The code assumes no transaction fees for buying and selling stocks. In real-world scenarios, transaction fees would need to be considered and incorporated into the profit calculation.
