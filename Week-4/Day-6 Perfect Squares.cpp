Day-6 Perfect Squares.cpp

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


*/

// Time:  O(n * sqrt(n))
// Space: O(n)
class Solution {
public:
    int numSquares(int n) {
        vector<int> num(n + 1, numeric_limits<int>::max());
        num[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = i - 1, k = 1; j >= 0; ++k, j = i - k * k) {
                num[i] = min(num[i], num[j] + 1);
            }
        }
        return num[n];
    }
};