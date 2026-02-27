/*
    Problem: Stock Span Problem
    Difficulty: Medium
    Topics: Stack, Array

    Description:
    The stock span problem is to calculate the span of stock’s price 
    for all days.

    The span of the stock’s price on a given day i is defined as the 
    maximum number of consecutive days just before the given day, 
    for which the price of the stock on the current day is 
    less than or equal to its price on the given day.

    Example:
    Input:
    Price = [100, 80, 60, 70, 60, 75, 85]

    Output:
    Span  = [1, 1, 1, 2, 1, 4, 6]

    -------------------------------------------------------
    Time Complexity:  O(n)
        - Each element is pushed and popped at most once.

    Space Complexity: O(n)
        - Stack stores indices.
    -------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculateSpan(vector<int>& price) {
    
    int n = price.size();
    vector<int> span(n);
    stack<int> st;  // stores indices

    for (int i = 0; i < n; i++) {

        // Pop elements while current price is greater
        while (!st.empty() && price[st.top()] <= price[i]) {
            st.pop();
        }

        // If stack becomes empty
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }

        // Push current index
        st.push(i);
    }

    return span;
}

int main() {

    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    vector<int> result = calculateSpan(price);

    cout << "Stock Spans: ";
    for (int val : result) {
        cout << val << " ";
    }

    return 0;
}