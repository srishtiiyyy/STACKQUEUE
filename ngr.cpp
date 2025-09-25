#include <bits/stdc++.h>
using namespace std;

/*
    ❓ Question: Next Greater Element
    Given an array arr[] of size N, for each element arr[i], 
    find the next greater element (NGE). 
    The Next Greater Element for an element x is the first greater element 
    on the right side of x in the array.
    If no such element exists, return -1 for that position.

    Example:
    Input:  arr = [4, 5, 2, 25]
    Output: [5, 25, 25, -1]

    Explanation:
    - For 4, the next greater element is 5.
    - For 5, the next greater element is 25.
    - For 2, the next greater element is 25.
    - For 25, there is no greater element → -1.
*/

// Function to compute Next Greater Element for each index
vector<int> nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;        // stack to keep possible "next greater elements"
    vector<int> ans(n);   // result array to store answers

    // Traverse array from right to left
    for (int i = n - 1; i >= 0; i--) {
        int currele = arr[i];

        // Remove all smaller or equal elements from stack 
        // (they can't be the next greater for arr[i])
        while (!st.empty() && st.top() <= currele) {
            st.pop();
        }

        // If stack is empty, no greater element exists to the right
        if (st.empty()) {
            ans[i] = -1;
        } 
        else {
            // Otherwise, top of stack is the next greater element
            ans[i] = st.top();
        }

        // Push current element into stack for future comparisons
        st.push(currele);
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Call the function directly (no object)
    vector<int> result = nextLargerElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
