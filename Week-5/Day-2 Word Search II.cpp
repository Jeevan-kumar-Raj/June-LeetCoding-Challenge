Day-2 Word Search II.cpp

/*

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
   Hide Hint #1  
You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?
   Hide Hint #2  
If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: Implement Trie (Prefix Tree) first.


*/




// Time:  O(m * n * h), h is height of trie
// Space: O(26^h)

class Solution {
private:
    struct TrieNode {
        bool isString = false;
        unordered_map<char, TrieNode *> leaves;
        
        bool Insert(const string& s) {
            auto* p = this;
            for (const auto& c : s) {
                if (p->leaves.find(c) == p->leaves.cend()) {
                    p->leaves[c] = new TrieNode;
                }
                p = p->leaves[c];
            }
            
            // s already existed in this trie.
            if (p->isString) {
                return false;
            } else {
                p->isString = true;
                return true;
            }
        }
        
        ~TrieNode() {
            for (auto& kv : leaves) {
                if (kv.second) {
                    delete kv.second;
                }
            }
        }
    };
    
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> ret;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        string cur;
        TrieNode trie;
        for (const auto& word : words) {
            trie.Insert(word);
        }
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                findWordsDFS(board, visited, &trie, i, j, cur,  ret);
            }
        }
        
        return vector<string>(ret.begin(), ret.end());
    }
    
    void findWordsDFS(vector<vector<char>> &grid,
             vector<vector<bool>> &visited,
             TrieNode *trie,
             int i,
             int j,
             string cur,
             unordered_set<string> &ret) {
        // Invalid state.
        if (!trie || i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return;
        }
        
        // Not in trie or visited.
        if (!trie->leaves[grid[i][j] ] || visited[i][j]) {
            return;
        }
        
        // Get next trie nodes.
        TrieNode *nextNode = trie->leaves[grid[i][j]];
        
        // Update current string.
        cur.push_back(grid[i][j]);
        
        // Find the string, add to the answers.
        if (nextNode->isString) {
            ret.insert(cur);
        }
        
        // Marked as visited.
        visited[i][j] = true;
        
        // Try each direction.
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        for (const auto& d : directions) {
            findWordsDFS(grid, visited, nextNode,
                         i + d.first, j + d.second, cur, ret);
        }
        
        visited[i][j] = false;
    }
};