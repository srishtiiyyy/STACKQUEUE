#include <bits/stdc++.h>
using namespace std;

/*
    ❓ Question: Next Smaller to Right (NSR)
    Given an array arr[] of size N, for each element arr[i], 
    find the nearest smaller element to its right.
    If no such element exists, return -1 for that position.

    Example:
    Input:  arr = [4, 5, 2, 10, 8]
    Output: [2, 2, -1, 8, -1]

    Explanation:
    - For 4, nearest smaller to right is 2
    - For 5, nearest smaller to right is 2
    - For 2, no smaller element to right → -1
    - For 10, nearest smaller to right is 8
    - For 8, no smaller element to right → -1
*/

// Function to compute Next Smaller Element to Right for each index
vector<int> nextSmallerToRight(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;        // stack to store potential "smaller" elements
    vector<int> ans(n);   // result array

    // Traverse array from right to left
    for (int i = n - 1; i >= 0; i--) {
        int currele = arr[i];

        // Remove all elements greater or equal (not useful for NSR)
        while (!st.empty() && st.top() >= currele) {
            st.pop();
        }

        // If stack is empty, no smaller element to the right
        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            // Otherwise, top of stack is the nearest smaller on the right
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
    vector<int> result = nextSmallerToRight(arr);

    cout << "Next Smaller to Right: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
