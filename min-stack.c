**Min Stack**

Problem Statement 55) Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.

--------------------------------------------------------------------------------------------------
SOLUTION = typedef struct Stack {
    int dataArray[10000];
    int top;
} MinStack;

void minStackGetMinForPush(MinStack*);
int min = 0; // For Minimum Element in the Stack
/** initialize your data structure here. */

MinStack* minStackCreate() {
    static MinStack stack;
    stack.top=-1;
    return &stack;
}

void minStackPush(MinStack* obj, int x) {
    if(obj->top == 10000){
       return;
    }
    else{
        obj->top++;
        obj->dataArray[obj->top] = x;
        minStackGetMinForPush(obj);
    }
}

void minStackPop(MinStack* obj) {
    if(obj->top == -1){
        return;
    } 
    else{
        obj->top--;
    }
    
    if(obj->top == -1){
        return;
    }
    int minTemp = obj->dataArray[obj->top];
    for(int i=0;i<obj->top;i++){
        if(minTemp>obj->dataArray[i]){
           minTemp = obj->dataArray[i];
        }
    }
    min = minTemp;
}

int minStackTop(MinStack* obj) {
    return obj->dataArray[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return min;
}

void minStackGetMinForPush(MinStack* obj){
    // if(obj->top == -1){
    //     return;
    // }
    
    if(obj->top==0){
        min = obj->dataArray[obj->top];
    }
    
    else if(obj->top>0){
        if(min > obj->dataArray[obj->top]){
            min = obj->dataArray[obj->top];
        }
    }
}

void minStackFree(MinStack* obj) {
    obj->top = -1;
}

--------------------------Explanation:- 
Structure Breakdown:

MinStack Structure:
dataArray: An array to store stack elements.
top: An integer representing the index of the top element.
**min: A global variable to store the current minimum value in the stack.
Function Breakdown:

minStackCreate():

Creates a static MinStack instance and initializes top to -1 (empty stack).
Returns a pointer to the created stack.
minStackPush(obj, x):

Checks for stack overflow.
Pushes x onto the stack by incrementing top and adding x to dataArray.
Updates the global min variable if necessary using minStackGetMinForPush.
minStackPop(obj):

Checks for stack underflow.
Pops the top element by decrementing top.
Recalculates the minimum value by iterating through the remaining elements if the popped element was the minimum.
minStackTop(obj):

Returns the top element of the stack without removing it.
minStackGetMin(obj):

Returns the current minimum value in the stack.
minStackGetMinForPush(obj):

Updates the global min variable if the new element being pushed is smaller than the current min.
minStackFree(obj):

Resets the stack to an empty state by setting top to -1.
Key Points:

Efficient Minimum Tracking: Uses a global variable min to track the minimum element, avoiding a full stack scan on every minStackGetMin call.
Trade-offs: Achieves constant time minStackGetMin but sacrifices some space for the global min variable.
Global Variable: The use of min might introduce potential issues in multi-threaded environments.
Alternative Approaches: Consider using a separate auxiliary stack to track minimum elements or storing additional information with each element.
Error Handling: The code doesn't handle empty stack conditions in some functions, which could lead to unexpected behavior.
Space Complexity: O(n) for the stack array and O(1) for the min variable.
Time Complexity:
Push, Pop, Top, GetMin: O(1)
Free: O(1) (but doesn't actually free memory)
