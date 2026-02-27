/*
    Problem: Valid Parentheses
    Difficulty: Easy
    Topics: Stack, String

    Description:
    Given a string s containing just the characters 
    '(', ')', '{', '}', '[' and ']', 
    determine if the input string is valid.

    -------------------------------------------------------
    Time Complexity:  O(n)
    Space Complexity: O(n)
    -------------------------------------------------------
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    static bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (st.empty())
                    return false;

                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};

int main() {

    string s;

    cout << "Enter parentheses string: ";
    cin >> s;

    if (Solution::isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}