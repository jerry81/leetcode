/*

1942. The Number of the Smallest Unoccupied Chair
Medium
Topics
Companies
Hint
There is a party where n friends numbered from 0 to n - 1 are attending. There
is an infinite number of chairs in this party that are numbered from 0 to
infinity. When a friend arrives at the party, they sit on the unoccupied chair
with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will
sit on chair number 2. When a friend leaves the party, their chair becomes
unoccupied at the moment they leave. If another friend arrives at that same
moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali,
leavingi], indicating the arrival and leaving times of the ith friend
respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.



Example 1:

Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation:
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
Example 2:

Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation:
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.


Constraints:

n == times.length
2 <= n <= 104
times[i].length == 2
1 <= arrivali < leavingi <= 105
0 <= targetFriend <= n - 1
Each arrivali time is distinct.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
20.1K
Submissions
45.5K
Acceptance Rate
44.1%

*/

#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  int smallestChair(vector<vector<int>>& times, int targetFriend) {
    vector<tuple<int, int, bool>> time_map;
    // organize by time
    int n = times.size();
    for (int friend_id = 0; friend_id < n; ++friend_id) {
      vector<int> time = times[friend_id];
      time_map.emplace_back(
          time[0], friend_id,
          true);  // til: emplace_back constructs directly unlike push_back
      time_map.emplace_back(time[1], friend_id, false);
    }

    sort(time_map.begin(), time_map.end(),
         [](const auto& a, const auto& b) {  // use this more, lambda
           if (get<0>(a) == get<0>(b)) {     // tuple accessors
             return !get<2>(a) && get<2>(b);
           }
           return get<0>(a) < get<0>(b);
         });

    priority_queue<int, vector<int>, greater<int>> availableChairs;

    for (int i = 0; i < times.size(); ++i) {
      availableChairs.push(i);  // Add all chairs to the heap
    }
    vector<int> chairAssignment(times.size(), -1);
    for (const auto& event : time_map) {
      int time = get<0>(event);
      int friendId = get<1>(event);
      bool isArrival = get<2>(event);

      if (isArrival) {
        int chair = availableChairs.top();
        availableChairs.pop();
        chairAssignment[friendId] =
            chair;
        if (friendId == targetFriend) {
          return chair;
        }
      } else {
        int chairNumber =
            chairAssignment[friendId];      // Get the chair number for the
                                            // departing friend
        availableChairs.push(chairNumber);  // Push the chair back into the heap
      }
    }
    return -1;
  }
};