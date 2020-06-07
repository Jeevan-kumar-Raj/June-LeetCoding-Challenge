Day-5 Random Pick with Weight.cpp

/*

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.


*/

// Time:  ctor: O(n)
//        pickIndex: O(logn)
// Space: O(n)

class Solution {
public:
    Solution(vector<int> w) :
        prefix_sum_(w.size()),
        uni_((random_device())()) {

        partial_sum(w.cbegin(), w.cend(), prefix_sum_.begin(), plus<int>());
        uni_ = uniform_int_distribution<int>{0, prefix_sum_.back() - 1};
    }
    
    int pickIndex() {
        const auto target = uni_(gen_);
        return distance(prefix_sum_.cbegin(),
                        upper_bound(prefix_sum_.cbegin(), prefix_sum_.cend(), target));
    }

private:
    vector<int> prefix_sum_;
    default_random_engine gen_;
    uniform_int_distribution<int> uni_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
