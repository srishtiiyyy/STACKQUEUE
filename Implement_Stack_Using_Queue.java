/*
Question: Implement Stack Using Queue

Problem Statement:
Implement a Last-In-First-Out (LIFO) stack using only the
standard operations of a queue.

Implement the following operations:

1. push(int x)    -> Push element x onto stack.
2. pop()          -> Removes and returns the element on top of the stack.
3. top()          -> Returns the top element.
4. isEmpty()      -> Returns true if the stack is empty.

Note:
Only standard queue operations are allowed:
- add()
- poll()
- peek()
- size()
- isEmpty()

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

Stack after push(10):
[10]

Stack after push(20):
[20, 10]

Stack after push(30):
[30, 20, 10]

top() returns 30
pop() removes 30
top() returns 20

Approach:
1. Use a single queue.
2. During push:
      - Insert the new element into the queue.
      - Rotate all previous elements behind it.
3. This ensures the newest element always stays at the front.
4. Therefore:
      - pop() becomes simple removal from front.
      - top() becomes peek from front.

Visualization:

push(10)
Queue = [10]

push(20)
Queue = [10,20]
Rotate once
Queue = [20,10]

push(30)
Queue = [20,10,30]
Rotate twice
Queue = [30,20,10]

Top of stack = Front of queue

Time Complexity:
push()    -> O(n)
pop()     -> O(1)
top()     -> O(1)
isEmpty() -> O(1)

Space Complexity:
O(n)

Related Questions:
1. Implement Queue Using Stacks (LeetCode 232)
2. Min Stack (LeetCode 155)
3. Design Circular Queue (LeetCode 622)
4. Design Circular Deque (LeetCode 641)
5. Valid Parentheses (LeetCode 20)
6. Next Greater Element

Company Tags:
Google, Microsoft, Amazon, Meta, Apple,
Netflix, Adobe, Accenture, TCS, Infosys,
Capgemini, Wipro, Cognizant

Commonly Asked In:
Product-Based Interviews and DSA Assessments
*/

import java.util.LinkedList;
import java.util.Queue;

class QueueStack {

    Queue<Integer> q;

    public QueueStack() {
        q = new LinkedList<>();
    }

    public void push(int x) {

        int size = q.size();

        q.add(x);

        for (int i = 0; i < size; i++) {
            q.add(q.poll());
        }
    }

    public int pop() {

        if (q.isEmpty()) {
            return -1;
        }

        return q.poll();
    }

    public int top() {

        if (q.isEmpty()) {
            return -1;
        }

        return q.peek();
    }

    public boolean isEmpty() {
        return q.isEmpty();
    }
}

public class Implement_Stack_Using_Queue {

    public static void main(String[] args) {

        QueueStack stack = new QueueStack();

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