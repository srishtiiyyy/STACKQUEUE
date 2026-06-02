/*
Question: Implement Stack Using Array

Problem Statement:
Design and implement a Stack data structure using an array.

Implement the following operations:
1. push(int x)    -> Insert an element into the stack.
2. pop()          -> Remove and return the top element of the stack.
                     Return -1 if the stack is empty.
3. top()          -> Return the top element without removing it.
                     Return -1 if the stack is empty.
4. isEmpty()      -> Return true if the stack is empty, otherwise false.

Example:

Input:
push(10)
push(20)
push(30)
top()
pop()
top()

Output:
30
30
20

Explanation:
Stack after push(10) -> [10]
Stack after push(20) -> [10, 20]
Stack after push(30) -> [10, 20, 30]

top() returns 30
pop() removes and returns 30
top() now returns 20

Approach:
1. Use an integer array to store stack elements.
2. Maintain a variable 'top' that points to the topmost element.
3. Initially top = -1 indicating an empty stack.
4. For push:
      - Increment top.
      - Insert element at arr[top].
5. For pop:
      - If stack is empty, return -1.
      - Store arr[top], decrement top, and return stored value.
6. For top:
      - Return arr[top] if stack is not empty.
7. For isEmpty:
      - Check if top == -1.

Time Complexity:
push()    -> O(1)
pop()     -> O(1)
top()     -> O(1)
isEmpty() -> O(1)

Space Complexity:
O(n)

Related Questions:
1. Implement Stack Using Linked List
2. Min Stack (LeetCode 155)
3. Implement Queue Using Stacks (LeetCode 232)
4. Valid Parentheses (LeetCode 20)
5. Next Greater Element
6. Daily Temperatures

Company Tags:
Epic Games, AMD, Target, MongoDB, Activision Blizzard,
PayPal, Goldman Sachs, Airbnb, Roblox, Teladoc Health,
Siemens Healthineers, Byju's, Salesforce, Alibaba,
American Express, ARM, Freshworks, Red Hat, Broadcom,
Rockstar Games, Intel, Docker, Twilio, Seagate Technology,
Unity Technologies, Google, Microsoft, Amazon, Meta,
Apple, Netflix, Adobe, TCS, Cognizant, Accenture,
Infosys, Capgemini, Wipro
*/

class ArrayStack {
    int[] arr;
    int top;

    public ArrayStack() {
        arr = new int[10000];
        top = -1;
    }

    public void push(int x) {
        top++;
        arr[top] = x;
    }

    public int pop() {
        if (top == -1)
            return -1;

        int ele = arr[top];
        top--;
        return ele;
    }

    public int top() {
        if (top == -1)
            return -1;

        return arr[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }
}

public class Implement_Stack_Using_Array {
    public static void main(String[] args) {

        ArrayStack stack = new ArrayStack();

        stack.push(10);
        stack.push(20);
        stack.push(30);

        System.out.println("Top Element: " + stack.top());

        System.out.println("Popped Element: " + stack.pop());

        System.out.println("Top Element After Pop: " + stack.top());

        System.out.println("Is Stack Empty? " + stack.isEmpty());

        stack.pop();
        stack.pop();

        System.out.println("Is Stack Empty After Removing All Elements? "
                + stack.isEmpty());
    }
}