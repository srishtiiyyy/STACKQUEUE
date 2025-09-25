#include <bits/stdc++.h>
using namespace std;

/*
   ✅ Question:
   You are given an integer array arr. 
   A subarray is a contiguous segment of the array. 
   For each subarray, find the minimum element.
   Return the sum of all these minimums, modulo 1e9+7.

   Example:
   Input: arr = [3,1,2,4]
   Subarrays:
   [3] -> min = 3
   [1] -> min = 1
   [2] -> min = 2
   [4] -> min = 4
   [3,1] -> min = 1
   [1,2] -> min = 1
   [2,4] -> min = 2
   [3,1,2] -> min = 1
   [1,2,4] -> min = 1
   [3,1,2,4] -> min = 1
   Sum = 17
*/

/*
   Helper Function 1:
   findNSE (Next Smaller Element to Right)
   For each element, finds the index of the next smaller element on the right.
   If none exists, store n (out of bounds index).
*/
vector<int> findNSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}

/*
   Helper Function 2:
   findPSEE (Previous Smaller Element to Left)
   For each element, finds the index of the previous smaller element on the left.
   If none exists, store -1.
*/
vector<int> findPSEE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}

/*
   Main Function:
   sumSubarrayMins(arr)
   Idea:
   - Each element arr[i] will be the minimum in some subarrays.
   - To count how many subarrays:
        left = distance to Previous Smaller Element
        right = distance to Next Smaller Element
        total subarrays where arr[i] is min = left * right
   - Contribution = arr[i] * left * right
   - Sum up all contributions modulo 1e9+7
*/
int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    int mod = 1e9 + 7;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        long long left = i - psee[i];
        long long right = nse[i] - i;
        long long freq = left * right;
        long long val = (freq * arr[i]) % mod;
        sum = (sum + val) % mod;
    }

    return (int)sum;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Sum of Subarray Minimums: " << sumSubarrayMins(arr) << endl;

    return 0;
}
