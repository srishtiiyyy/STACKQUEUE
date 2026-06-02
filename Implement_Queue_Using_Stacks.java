/*
Question: Implement Queue Using Stacks

Problem Statement:
Implement a First-In-First-Out (FIFO) Queue using only Stack operations.

Implement the following operations:

1. push(int x)    -> Insert element at the rear of the queue.
2. pop()          -> Remove and return the front element.
3. peek()         -> Return the front element.
4. isEmpty()      -> Check whether the queue is empty.

A queue follows FIFO order:
First element inserted is the first one removed.

--------------------------------------------------

Approach 1: Push Efficient (Amortized O(1) Push)

Data Structures:
- input stack
- output stack

Working:
1. push():
      Insert directly into input stack.

2. pop()/peek():
      If output stack is empty:
          Move all elements from input to output.
      Then perform pop/peek from output.

Why it works?
Moving elements reverses the order,
making the oldest element appear at the top
of the output stack.

Example:

push(10)
push(20)
push(30)

Input Stack:
[10,20,30]

Output Stack:
[]

pop()

Transfer:
Input -> Output

Output:
[30,20,10]

pop() returns 10

Time Complexity:
push()  -> O(1)
pop()   -> O(1) amortized
peek()  -> O(1) amortized

Space Complexity:
O(n)

--------------------------------------------------

Approach 2: Pop Efficient (O(n) Push)

Data Structures:
- stack1
- stack2

Working:
1. Move all elements from stack1 to stack2.
2. Insert new element into stack1.
3. Move everything back from stack2 to stack1.

This ensures the queue front always remains
at the top of stack1.

Example:

push(10)
stack1 = [10]

push(20)

Move 10 -> stack2
Insert 20
Move 10 back

stack1 = [20,10]

Top = Queue Front

Time Complexity:
push()  -> O(n)
pop()   -> O(1)
peek()  -> O(1)

Space Complexity:
O(n)

--------------------------------------------------

Related Questions:
1. LeetCode 232 - Implement Queue using Stacks
2. LeetCode 225 - Implement Stack using Queues
3. LeetCode 155 - Min Stack
4. LeetCode 622 - Design Circular Queue
5. LeetCode 641 - Design Circular Deque
6. LRU Cache
7. Sliding Window Maximum

Company Tags:
GE Healthcare, Deloitte, eBay, Zoho,
Red Hat, Mastercard, DoorDash, Roblox,
PayPal, Oracle, KPMG, Dropbox, Alibaba,
HCL Technologies, Airbnb, Texas Instruments,
Zomato, Chewy, IBM, Twilio, Bain & Company,
Siemens Healthineers, Bungie, Roche, Splunk,
Google, Microsoft, Amazon, Meta, Apple,
Netflix, Adobe, TCS, Cognizant, Accenture,
Infosys, Capgemini, Wipro
*/

import java.util.Stack;

/* =====================================================
   APPROACH 1 : PUSH O(1), POP O(1) AMORTIZED
   ===================================================== */

class QueueUsingStacksOptimal {

    private Stack<Integer> input;
    private Stack<Integer> output;

    public QueueUsingStacksOptimal() {
        input = new Stack<>();
        output = new Stack<>();
    }

    // O(1)
    public void push(int x) {
        input.push(x);
    }

    // O(1) amortized
    public int pop() {

        if (output.isEmpty()) {
            while (!input.isEmpty()) {
                output.push(input.pop());
            }
        }

        if (output.isEmpty()) {
            return -1;
        }

        return output.pop();
    }

    // O(1) amortized
    public int peek() {

        if (output.isEmpty()) {
            while (!input.isEmpty()) {
                output.push(input.pop());
            }
        }

        if (output.isEmpty()) {
            return -1;
        }

        return output.peek();
    }

    public boolean isEmpty() {
        return input.isEmpty() && output.isEmpty();
    }
}

/* =====================================================
   APPROACH 2 : PUSH O(n), POP O(1)
   ===================================================== */

class QueueUsingStacksPushCostly {

    private Stack<Integer> st1;
    private Stack<Integer> st2;

    public QueueUsingStacksPushCostly() {
        st1 = new Stack<>();
        st2 = new Stack<>();
    }

    // O(n)
    public void push(int x) {

        while (!st1.isEmpty()) {
            st2.push(st1.pop());
        }

        st1.push(x);

        while (!st2.isEmpty()) {
            st1.push(st2.pop());
        }
    }

    // O(1)
    public int pop() {

        if (st1.isEmpty()) {
            return -1;
        }

        return st1.pop();
    }

    // O(1)
    public int peek() {

        if (st1.isEmpty()) {
            return -1;
        }

        return st1.peek();
    }

    public boolean isEmpty() {
        return st1.isEmpty();
    }
}

/* =====================================================
   DRIVER CLASS
   ===================================================== */

public class Implement_Queue_Using_Stacks {

    public static void main(String[] args) {

        System.out.println("===== Approach 1 : Push O(1) =====");

        QueueUsingStacksOptimal q1 = new QueueUsingStacksOptimal();

        q1.push(10);
        q1.push(20);
        q1.push(30);

        System.out.println("Front Element: " + q1.peek());
        System.out.println("Removed Element: " + q1.pop());
        System.out.println("Front Element After Pop: " + q1.peek());
        System.out.println("Is Queue Empty? " + q1.isEmpty());

        System.out.println();

        System.out.println("===== Approach 2 : Push O(n) =====");

        QueueUsingStacksPushCostly q2 = new QueueUsingStacksPushCostly();

        q2.push(10);
        q2.push(20);
        q2.push(30);

        System.out.println("Front Element: " + q2.peek());
        System.out.println("Removed Element: " + q2.pop());
        System.out.println("Front Element After Pop: " + q2.peek());
        System.out.println("Is Queue Empty? " + q2.isEmpty());
    }
}