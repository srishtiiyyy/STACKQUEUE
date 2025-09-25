/*
====================================================================
LeetCode 402: Remove K Digits
====================================================================

📝 Problem Statement:
Given a non-negative integer num represented as a string, remove k digits
from the number so that the new number is the smallest possible.

Return the new number as a string.

--------------------------------------------------------------------
Example 1:
Input: num = "1432219", k = 3
Output: "1219"

Example 2:
Input: num = "10200", k = 1
Output: "200"

Example 3:
Input: num = "10", k = 2
Output: "0"

--------------------------------------------------------------------
💡 Approach:
Use a stack-like string to maintain the smallest possible number:
1. Iterate over each digit of the input.
2. While the last digit in the result is greater than the current digit
   and k > 0, remove the last digit (pop).
3. Avoid leading zeros when pushing new digits.
4. If any removals are left after the loop, remove from the end.
5. If the result is empty, return "0".

Time Complexity: O(n)
Space Complexity: O(n)

====================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// -------------------- SOLUTION FUNCTION --------------------
string removeKdigits(string num, int k) {
    string res = "";
    int n = num.length();

    for (int i = 0; i < n; i++) {
        // Remove larger digits from the end if current is smaller
        while (res.length() > 0 && k > 0 && res.back() > num[i]) {
            res.pop_back();
            k--;
        }
        // Avoid leading zeros
        if (res.length() > 0 || num[i] != '0') {
            res.push_back(num[i]);
        }
    }

    // If k removals left, remove from the end
    while (k > 0 && res.length() > 0) {
        res.pop_back();
        k--;
    }

    // If empty, return "0"
    if (res == "") return "0";
    return res;
}

// -------------------- MAIN FUNCTION --------------------
int main() {
    string num1 = "1432219";
    int k1 = 3;
    string num2 = "10200";
    int k2 = 1;
    string num3 = "10";
    int k3 = 2;

    cout << "Test 1: " << removeKdigits(num1, k1) << endl; // Expected "1219"
    cout << "Test 2: " << removeKdigits(num2, k2) << endl; // Expected "200"
    cout << "Test 3: " << removeKdigits(num3, k3) << endl; // Expected "0"

    return 0;
}
