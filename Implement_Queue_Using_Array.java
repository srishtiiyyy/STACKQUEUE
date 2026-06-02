/*
Question: Implement Queue Using Array

Problem Statement:
Design and implement a Queue data structure using an array.

Implement the following operations:
1. push(int x)    -> Insert an element at the rear of the queue.
2. pop()          -> Remove and return the front element.
                     Return -1 if the queue is empty.
3. peek()         -> Return the front element without removing it.
4. isEmpty()      -> Return true if the queue is empty, otherwise false.

Example:

Input:
push(10)
push(20)
push(30)
peek()
pop()
peek()

Output:
10
10
20

Explanation:
Queue after push(10) -> [10]
Queue after push(20) -> [10, 20]
Queue after push(30) -> [10, 20, 30]

peek() returns 10
pop() removes and returns 10
peek() now returns 20

Approach:
1. Use an array to store queue elements.
2. Maintain two pointers:
      - start -> points to front element.
      - end   -> points to rear element.
3. Initially:
      start = -1
      end = -1
4. For first insertion:
      - Set start = 0 and end = 0.
5. For subsequent insertions:
      - Increment end and insert element.
6. For deletion:
      - Remove element at start.
      - If queue becomes empty, reset both pointers to -1.
      - Otherwise increment start.
7. For peek:
      - Return front element.
8. For isEmpty:
      - Check whether start == -1.

Time Complexity:
push()    -> O(1)
pop()     -> O(1)
peek()    -> O(1)
isEmpty() -> O(1)

Space Complexity:
O(n)

Note:
This implementation is a simple array-based queue.
After many deletions, unused space at the beginning of the array
cannot be reused. A Circular Queue is a better optimized version.

Related Questions:
1. Implement Circular Queue
2. Implement Queue Using Stacks (LeetCode 232)
3. Design Circular Deque (LeetCode 641)
4. First Unique Character in a Stream
5. Sliding Window Maximum
6. Rotten Oranges

Company Tags:
Boston Consulting Group, Nutanix, Morgan Stanley,
Wayfair, Pinterest, PayPal, Visa, Medtronic,
HashiCorp, Johnson & Johnson, Snowflake,
Cloudflare, Ernst & Young, Siemens Healthineers,
Texas Instruments, NVIDIA, Riot Games,
Epic Systems, American Express, Chewy,
Robinhood, Flipkart, Bloomberg, Rockstar Games,
Dropbox, Google, Microsoft, Amazon, Meta,
Apple, Netflix, Adobe, TCS, Cognizant,
Accenture, Infosys, Capgemini, Wipro
*/

class ArrayQueue {
    int[] arr;
    int start;
    int end;

    public ArrayQueue() {
        arr = new int[1000];
        start = -1;
        end = -1;
    }

    public void push(int x) {
        if (start == -1 && end == -1) {
            start = 0;
            end = 0;
            arr[end] = x;
        } else {
            end++;
            arr[end] = x;
        }
    }

    public int pop() {
        if (start == -1) {
            return -1;
        }

        int ele = arr[start];

        if (start == end) {
            start = -1;
            end = -1;
        } else {
            start++;
        }

        return ele;
    }

    public int peek() {
        if (start == -1) {
            return -1;
        }

        return arr[start];
    }

    public boolean isEmpty() {
        return start == -1;
    }
}

public class Implement_Queue_Using_Array {

    public static void main(String[] args) {

        ArrayQueue queue = new ArrayQueue();

        queue.push(10);
        queue.push(20);
        queue.push(30);

        System.out.println("Front Element: " + queue.peek());

        System.out.println("Removed Element: " + queue.pop());

        System.out.println("Front Element After Pop: " + queue.peek());

        System.out.println("Is Queue Empty? " + queue.isEmpty());

        queue.pop();
        queue.pop();

        System.out.println("Is Queue Empty After Removing All Elements? "
                + queue.isEmpty());
    }
}