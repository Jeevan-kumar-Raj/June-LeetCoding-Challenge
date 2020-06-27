Day-3 Unique Binary Search Trees.cpp

/*Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3




*/

class Solution {
    int catalan_Number(int n)
    {
        int catalan[n+1];
        catalan[0] = catalan[1] = 1;
        
        for(int i=2;i<=n;++i)
        {
            catalan[i] = 0;
            for(int j=0;j<i;++j)
                catalan[i] += catalan[j]*catalan[i-j-1];
        }
        return catalan[n];
    }
public:
    int numTrees(int n) {
        return catalan_Number(n);
    }
};
