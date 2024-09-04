#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const vector<pair<int, int>> DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // N, E, S, W
        unordered_map<int, unordered_set<int>> lookup;

        for (auto& v : obstacles) {
            int x = v[0];
            int y = v[1];
            lookup[x].insert(y);
        }

        int x = 0, y = 0;  // Robot's starting position
        int dir = 0;  // Start facing North
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -2) {
                // Turn left
                dir = (dir + 3) % 4; // this takes care of the negative number conundrum
            } else if (cmd == -1) {
                // Turn right
                dir = (dir + 1) % 4;
            } else {
                // Move forward
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + DIRS[dir].first;
                    int ny = y + DIRS[dir].second;
                    if (lookup[nx].count(ny)) {
                        break;  // Stop if there's an obstacle
                    }
                    x = nx;
                    y = ny;
                    maxDistSq = max(maxDistSq, x * x + y * y);
                }
            }
        }

        return maxDistSq;
    }
};
