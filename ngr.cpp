/*
    ❓ Question: Next Greater Element
    Given an array arr[] of size N, for each element arr[i], 
    find the next greater element (NGE). 
    The Next Greater Element for an element x is the first greater element 
    on the right side of x in the array.
    If no such element exists, print -1.

    Example:
    Input:  arr = [4, 5, 2, 25]
    Output: [5, 25, 25, -1]

    Explanation:
    - For 4, the next greater element is 5.
    - For 5, the next greater element is 25.
    - For 2, the next greater element is 25.
    - For 25, there is no greater element → -1.
*/

class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        stack<int> st;        // stack to store potential next greater elements
        vector<int> ans(n);   // answer array

        // Traverse from right to left because we are looking for "next greater"
        for (int i = n - 1; i >= 0; i--) {
            int currele = arr[i];

            // Pop all elements from stack that are <= current element
            // Because they can't be the next greater element for arr[i]
            while (!st.empty() && st.top() <= currele) {
                st.pop();
            }

            // If stack becomes empty, it means no greater element exists on the right
            if (st.empty()) {
                ans[i] = -1;
            } 
            else {
                // Top of stack is the next greater element
                ans[i] = st.top();
            }

            // Push current element onto stack so it can be a candidate for future elements
            st.push(currele);
        }

        return ans;
    }
};
