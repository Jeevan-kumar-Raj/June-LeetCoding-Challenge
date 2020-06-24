Day-1 Single Number II.cpp

/*

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;

        for (const auto& i : nums) {
            int new_one = (~i & one) | (i & ~one & ~two);
            int new_two = (~i & two) | (i & one);
            one = new_one, two = new_two;
        }

        return one;
    }
};