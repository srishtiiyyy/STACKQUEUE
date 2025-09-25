#include <bits/stdc++.h>
using namespace std;

/*
    ❓ Question: Next Smaller to Left (NSL)
    Given an array arr[] of size N, for each element arr[i], 
    find the nearest smaller element to its left.
    If no such element exists, return -1 for that position.

    Example:
    Input:  arr = [4, 5, 2, 10, 8]
    Output: [-1, 4, -1, 2, 2]

    Explanation:
    - For 4, there is no element to the left → -1
    - For 5, nearest smaller on left is 4
    - For 2, no smaller element on left → -1
    - For 10, nearest smaller on left is 2
    - For 8, nearest smaller on left is 2
*/

// Function to compute Next Smaller Element to Left for each index
vector<int> nextSmallerToLeft(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;        // stack to store potential "smaller" elements
    vector<int> ans(n);   // result array

    // Traverse array from left to right
    for (int i = 0; i < n; i++) {
        int currele = arr[i];

        // Remove all elements greater or equal (not useful for NSL)
        while (!st.empty() && st.top() >= currele) {
            st.pop();
        }

        // If stack is empty, no smaller element to the left
        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            // Otherwise, top of stack is the nearest smaller on the left
            ans[i] = st.top();
        }

        // Push current element for future comparisons
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

    // Direct function call
    vector<int> result = nextSmallerToLeft(arr);

    cout << "Next Smaller to Left: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
