#include <bits/stdc++.h>
using namespace std;

/*
    ❓ Question: Next Greater Element I
    You are given two arrays nums1 and nums2 where nums1 is a subset of nums2.
    For each element in nums1, find the next greater element in nums2.

    The Next Greater Element of x in nums2 is the first greater element 
    to the right of x in nums2. If it does not exist, return -1.

    Example:
    Input:  nums1 = [4,1,2], nums2 = [1,3,4,2]
    Output: [-1,3,-1]

    Explanation:
    - For 4 in nums1 → In nums2 = [1,3,4,2], next greater is -1
    - For 1 in nums1 → Next greater is 3
    - For 2 in nums1 → Next greater is -1
*/

// Function to find Next Greater Elements for nums1 based on nums2
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> next; // stores {element → next greater}
    stack<int> s;  // monotonic stack (decreasing)

    // Process nums2 from right to left
    for (int i = nums2.size() - 1; i >= 0; --i) {
        // Remove smaller or equal elements (they can't be next greater)
        while (!s.empty() && s.top() <= nums2[i]) {
            s.pop();
        }
        // If stack empty → no greater element, else top is next greater
        next[nums2[i]] = s.empty() ? -1 : s.top();

        // Push current element for future checks
        s.push(nums2[i]);
    }

    // Build result for nums1 using precomputed map
    vector<int> res;
    for (int num : nums1) {
        res.push_back(next[num]);
    }
    return res;
}

int main() {
    int n1, n2;
    cout << "Enter size of nums1: ";
    cin >> n1;
    cout << "Enter size of nums2: ";
    cin >> n2;

    vector<int> nums1(n1), nums2(n2);

    cout << "Enter elements of nums1: ";
    for (int i = 0; i < n1; i++) cin >> nums1[i];

    cout << "Enter elements of nums2: ";
    for (int i = 0; i < n2; i++) cin >> nums2[i];

    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
