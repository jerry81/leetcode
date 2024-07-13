
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int sz = positions.size();
        vector<tuple<int, int, char, int>> robots(sz);

        for (int i = 0; i < sz; ++i) {
            robots[i] = {positions[i], healths[i], directions[i], i}; // Include the initial index
        }

        // Sort robots by positions
        sort(robots.begin(), robots.end());

        stack<int> stk;
        for (int i = 0; i < sz; ++i) {
            auto [p, h, d, idx] = robots[i];
            if (d == 'R') {
                stk.push(i);
            } else {
                while (!stk.empty() && get<2>(robots[stk.top()]) == 'R') {
                    int j = stk.top();
                    auto [tp, th, td, tidx] = robots[j];
                    if (th == h) {
                        robots[j] = {tp, 0, 'X', tidx}; // Remove right-moving robot
                        robots[i] = {p, 0, 'X', idx};  // Remove left-moving robot
                        stk.pop();
                        break;
                    } else if (th > h) {
                        robots[j] = {tp, th - 1, 'R', tidx}; // Right-moving robot survives with reduced health
                        robots[i] = {p, 0, 'X', idx};  // Remove left-moving robot
                        break;
                    } else {
                        robots[j] = {tp, 0, 'X', tidx}; // Remove right-moving robot
                        robots[i] = {p, h - 1, 'L', idx}; // Left-moving robot survives with reduced health
                        stk.pop();
                    }
                }
            }
        }

        vector<int> result(sz);
        for (int i = 0; i < sz; ++i) {
            auto [p, h, d, idx] = robots[i];
            if (h > 0) {
                result[idx] = h;
            }
        }

        // Filter out the zeros which represent non-surviving robots
        result.erase(remove(result.begin(), result.end(), 0), result.end());

        return result;
    }
};