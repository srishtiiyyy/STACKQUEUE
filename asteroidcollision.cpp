#include <bits/stdc++.h>
using namespace std;

/*
    ❓ Problem: Asteroid Collision
    We are given an array asteroids of integers representing asteroids moving in a row.

    - Each asteroid moves at the same speed.
    - Positive value → asteroid moving to the right.
    - Negative value → asteroid moving to the left.
    - When two asteroids collide, the smaller one (absolute value) explodes.
    - If both are the same size, both explode.
    - Asteroids moving in the same direction never meet.

    Return the state of the asteroids after all collisions.

    Example:
    Input:  [5, 10, -5]
    Output: [5, 10]

    Explanation:
    - 10 and -5 collide → -5 explodes (since 10 > 5)
    - Remaining: [5, 10]
*/

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> st; // using vector as a stack

    for (int i = 0; i < n; i++) {
        if (asteroids[i] > 0) {
            // Moving right → just push
            st.push_back(asteroids[i]);
        } else {
            // Moving left → possible collision
            while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                // Top asteroid is smaller → it explodes
                st.pop_back();
            }

            if (!st.empty() && st.back() == abs(asteroids[i])) {
                // Both are equal → both explode
                st.pop_back();
            } else if (st.empty() || st.back() < 0) {
                // No collision → safe to push
                st.push_back(asteroids[i]);
            }
        }
    }

    return st; // final state
}

int main() {
    int n;
    cout << "Enter number of asteroids: ";
    cin >> n;

    vector<int> asteroids(n);
    cout << "Enter asteroid values (positive=right, negative=left): ";
    for (int i = 0; i < n; i++) cin >> asteroids[i];

    vector<int> result = asteroidCollision(asteroids);

    cout << "Final state after collisions: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
