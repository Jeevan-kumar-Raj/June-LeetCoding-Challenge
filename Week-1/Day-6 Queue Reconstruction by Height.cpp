Day-6 Queue Reconstruction by Height.cpp

/*

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

//Time:  O(n^2)
//Space: O(n)
void print_vector(vector<vector<int> > v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << "[";
      for(int j = 0; j <v[i].size(); j++){
         cout << v[i][j] << ", ";
      }
      cout << "],";
   }
   cout << "]"<<endl;
}
bool cmp(vector <int> a, vector <int> b){
   if(a[0] == b[0])return a[1] > b[1];
      return a[0] < b[0];
}
class Solution {
public:
   vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
      sort(p.begin(), p.end(), cmp);
      vector < vector <int> > ans;
      for(int i = p.size()-1; i>=0; i--){
         ans.insert(ans.begin() + p[i][1], p[i]);
      }
      return ans;
   }
};
