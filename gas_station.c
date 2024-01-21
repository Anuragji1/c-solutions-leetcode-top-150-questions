**Gas Station**

Problem Statement 14) There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

 

Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
 

Constraints:

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104

-------------------------------------------------------------------------------------------------------------------------------------
SOLUTION = int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total = 0, start = 0, tank = 0;

    for (int i = 0; i < gasSize; i++) {
        total += gas[i] - cost[i];  // Calculate total gas gained/lost
        tank += gas[i] - cost[i];  // Track current gas in the tank

        if (tank < 0) {  // If we run out of gas, reset start and tank
            start = i + 1;
            tank = 0;
        }
    }

    return total >= 0 ? start : -1;  // Return start if total gas is non-negative, otherwise -1
}


---------------------------------Explanation :- 
Purpose:

The code implements a function named canCompleteCircuit() that determines if there exists a starting point in a circular gas station array where a car can complete a full circuit without running out of gas. It also returns the starting index if such a point exists.
Key Steps:

Variable Initialization:

total: Tracks the total net gas gained or lost throughout the entire circuit.
start: Stores the potential starting index for a successful circuit.
tank: Represents the current amount of gas in the tank.
Iterating Through Gas Stations:

The code iterates through each gas station in the array:
It calculates the net gas change at each station by subtracting the cost from the available gas.
It updates both total and tank with this net gas change.
If the tank becomes negative at any point, it means the car cannot reach the current station from the current starting point. So, it resets start to the next station and tank to 0 to start a new potential circuit.
Checking Feasibility and Returning Result:

After the iteration, if the total net gas is non-negative (total >= 0), it means a complete circuit is possible, and the function returns the start index.
Otherwise, it returns -1 to indicate no feasible starting point exists.
Logic:

The code leverages the idea that if a complete circuit is possible, the total net gas must be non-negative.
It also efficiently identifies the starting point by resetting whenever a potential circuit fails due to insufficient gas.
Time and Space Complexity:

Time Complexity: O(n), where n is the number of gas stations. The algorithm performs a single linear pass through the array.
Space Complexity: O(1), as it uses only a constant amount of extra space for variables.
