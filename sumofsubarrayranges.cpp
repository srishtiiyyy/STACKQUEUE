/*
====================================================================
LeetCode 2104: Sum of Subarray Ranges
====================================================================

📝 Problem Statement:
You are given an integer array `nums`. 
The range of a subarray of `nums` is the difference between the maximum 
and minimum element in the subarray.

Return the sum of all subarray ranges of `nums`.

--------------------------------------------------------------------
Example 1:
Input: nums = [1,2,3]
Output: 4

Example 2:
Input: nums = [1,3,3]
Output: 4

Example 3:
Input: nums = [4,-2,-3,4,1]
Output: 59

--------------------------------------------------------------------
💡 Approach:
Instead of generating all subarrays, we calculate contribution of 
each element using monotonic stacks.

- For MINIMUMS: 
  Find how many subarrays where the element is minimum.  
- For MAXIMUMS: 
  Find how many subarrays where the element is maximum.  

Final Answer = (Sum of max contributions) - (Sum of min contributions)

Time Complexity: O(n)
Space Complexity: O(n)

====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ---------- Next Smaller Element ----------
    static vector<int> findNSE(vector<int> &arr) {
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

    // ---------- Previous Smaller or Equal Element ----------
    static vector<int> findPSEE(vector<int> &arr) {
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

    // ---------- Next Greater Element ----------
    static vector<int> findNGE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

    // ---------- Previous Greater or Equal Element ----------
    static vector<int> findPGEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

    // ---------- Sum of Subarray Minimums ----------
    static long long sumSubarrayMins(vector<int> &arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int n = arr.size();
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];   // subarrays on left
            long long right = nse[i] - i;   // subarrays on right
            sum += left * right * 1LL * arr[i];
        }
        return sum;
    }

    // ---------- Final Function: Sum of Subarray Ranges ----------
    static long long subArrayRanges(vector<int>& nums) {
        vector<int> nge = findNGE(nums);
        vector<int> pgee = findPGEE(nums);

        int n = nums.size();
        long long maxSum = 0;

        // Contribution as maximum
        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            maxSum += left * right * 1LL * nums[i];
        }

        // Contribution as minimum
        long long minSum = sumSubarrayMins(nums);

        // Final Answer
        return maxSum - minSum;
    }
};

// -------------------- MAIN FUNCTION --------------------
int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {1, 3, 3};
    vector<int> nums3 = {4, -2, -3, 4, 1};

    cout << "Test 1: " << Solution::subArrayRanges(nums1) << endl; // Expected 4
    cout << "Test 2: " << Solution::subArrayRanges(nums2) << endl; // Expected 4
    cout << "Test 3: " << Solution::subArrayRanges(nums3) << endl; // Expected 59

    return 0;
}
