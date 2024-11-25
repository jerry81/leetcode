#include <string>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int slidingPuzzle(vector<vector<int>>& board) {
    const string TARGET = "123450";
    const vector<vector<int>> MOVES = {{1, 3}, {0, 2, 4}, {1, 5},
                                       {0, 4}, {1, 3, 5}, {2, 4}};

    // Convert board to string format
    string start = "";
    int zeroIndex = 0; // Position of '0'
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        start += (board[i][j] + '0');
        if (board[i][j] == 0) zeroIndex = i * 3 + j;
      }
    }

    // BFS setup
    queue<pair<string, int>> q; // {current state, zero index}
    unordered_set<string> visited;
    q.push({start, zeroIndex});
    visited.insert(start);

    int moves = 0;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        auto [cur, zeroPos] = q.front();
        q.pop();

        if (cur == TARGET) return moves;

        // Explore all moves
        for (int nextPos : MOVES[zeroPos]) {
          string next = cur;
          swap(next[zeroPos], next[nextPos]);
          if (visited.find(next) == visited.end()) {
            q.push({next, nextPos});
            visited.insert(next);
          }
        }
      }
      ++moves;
    }

    return -1; // If no solution
  }
};