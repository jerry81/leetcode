/*
Keys and Rooms

Solution
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.



Example 1:

Input: rooms = [[1],[2],[3],[]]
Output: true
Explanation:
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
Example 2:

Input: rooms = [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can not enter room number 2 since the only key that unlocks it is in that room.


Constraints:

n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
All the values of rooms[i] are unique.
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      unordered_map<int, bool> visited;
      vector<int> to_visit;
      to_visit.push_back(0);
      visited[0]=true;
      while (!to_visit.empty()) {
        int next = to_visit.back();
        vector<int> keys = rooms.at(next);
        to_visit.pop_back();
        for (int i:keys) {
          if (!visited[i]) {
            to_visit.push_back(i);
            visited[i] = true;
          }
        }
      }
      return visited.size() == rooms.size();
    }
};

int main() {
  Solution s = Solution();
  vector<vector<int>> example;
  vector<int> a;
  a.push_back(1);
  vector<int> b;
  a.push_back(2);
  vector<int> c;
  a.push_back(3);
  vector<int> d;
  cerr << "im starting " << endl;
  example.push_back(a);
  cerr << "can i do this " << endl;
  example.push_back(b);
    example.push_back(c);
      example.push_back(d);
  cerr << "expect 1 " << s.canVisitAllRooms(example) << endl;
}