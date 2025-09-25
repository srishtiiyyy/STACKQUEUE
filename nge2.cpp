#include <bits/stdc++.h>
using namespace std;

/*
    ❓ Question: Next Greater Element II (Circular Array)
    Given a circular array nums[] of size N, find the Next Greater Element (NGE) 
    for every element. The Next Greater Element of an element x is the first 
    greater element to the right of x in the array. 
    If no such element exists, return -1.

    Note: The array is circular → after the last element, 
    it continues again from the first element.

    Example:
    Input:  nums = [1, 2, 1]
    Output: [2, -1, 2]

    Explanation:
    - For nums[0] = 1 → Next greater is 2
    - For nums[1] = 2 → No greater element → -1
    - For nums[2] = 1 → Next greater is 2 (from the circular wrap-around)
*/

// Function to compute Next Greater Elements in circular array
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    // Traverse array twice (simulate circularity)
    for (int i = 2 * n - 1; i >= 0; i--) {
        int ind = i % n;   // current index in circular manner
        int currele = nums[ind];

        // Remove all smaller or equal elements (not useful for NGE)
        while (!st.empty() && st.top() <= currele) {
            st.pop();
        }

        // Fill answer only in the first pass
        if (i < n) {
            if (st.empty()) {
                ans[ind] = -1;  // no greater element
            } else {
                ans[ind] = st.top();  // next greater element
            }
        }

        // Push current element into stack for future checks
        st.push(currele);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> result = nextGreaterElements(nums);

    cout << "Next Greater Elements (Circular): ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
