**Best Time to Buy and Sell Stock**

Problem Statement 7) You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

----------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int maxProfit(int* prices, int pricesSize) {
    int minPrice = INT_MAX, maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        minPrice = fmin(minPrice, prices[i]);  // Track the minimum price so far
        maxProfit = fmax(maxProfit, prices[i] - minPrice);  // Calculate potential profit
    }

    return maxProfit;
}


-------------------------Explanation :-
Purpose:

The code implements a function named maxProfit() that calculates the maximum profit that can be achieved by buying and selling a stock once, given a list of daily stock prices.
Key Steps:

Initialization:

minPrice is initialized to INT_MAX to represent the highest possible price, ensuring it's updated with the actual minimum price encountered.
maxProfit is initialized to 0 to track the maximum profit found so far.
Iteration Through Prices:

The code iterates through each price in the prices array:
It updates minPrice to the minimum of its current value and the current price, effectively tracking the lowest price seen so far.
It calculates the potential profit by subtracting the minPrice from the current price and updates maxProfit if a higher profit is found.
Return Maximum Profit:

After iterating through all prices, the function returns the maxProfit value, representing the highest possible profit achievable by buying at the lowest price and selling at the highest price.
Time and Space Complexity:

Time Complexity: O(n), where n is the number of prices in the array. The algorithm performs a single linear pass through the array.
Space Complexity: O(1), as it uses only a constant amount of extra space for variables, regardless of the input size.
