#include <bits/stdc++.h>
using namespace std;

/*
    ❓ Question: Next Greater to Left (NGL)
    Given an array arr[] of size N, for each element arr[i], 
    find the nearest greater element to its left.
    If no such element exists, return -1 for that position.

    Example:
    Input:  arr = [1, 3, 2, 4]
    Output: [-1, -1, 3, -1]

    Explanation:
    - For 1, there is no element to the left → -1
    - For 3, no greater element exists to its left → -1
    - For 2, the nearest greater to left is 3
    - For 4, no greater element exists to its left → -1
*/

// Function to compute Next Greater Element to Left for each index
vector<int> nextGreaterToLeft(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;        // stack to store potential "greater" elements
    vector<int> ans(n);   // result array

    // Traverse array from left to right (opposite of NGR)
    for (int i = 0; i < n; i++) {
        int currele = arr[i];

        // Remove all smaller or equal elements (not useful for NGL)
        while (!st.empty() && st.top() <= currele) {
            st.pop();
        }

        // If stack is empty, no greater element to the left
        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            // Otherwise, top of stack is the nearest greater on the left
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

    // Direct function call (no object)
    vector<int> result = nextGreaterToLeft(arr);

    cout << "Next Greater to Left: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
