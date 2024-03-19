/*
621. Task Scheduler
Medium
Topics
Companies
You are given an array of CPU tasks, each represented by letters A to Z, and a
cooling time, n. Each cycle or interval allows the completion of one task. Tasks
can be completed in any order, but there's a constraint: identical tasks must be
separated by at least n intervals due to cooling time.

​Return the minimum number of intervals required to complete all tasks.



Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two cycles before doing A again. The same
applies to task B. In the 3rd interval, neither A nor B can be done, so you
idle. By the 4th cycle, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle ->
idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3
intervals. This leads to idling twice between repetitions of these tasks.



Constraints:

1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
519.8K
Submissions
890.3K
Acceptance Rate
58.4%
*/

#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<char, int> freq;

 public:
  int leastInterval(vector<char>& tasks, int n) {
    std::priority_queue<int> pq;  // new way to do custom sort, interesting

    //  so apparently last index doesn't matter
    /*
      nested while
      while pq has more elements
        while pq has more elements (cycle-wise)
        and the cycle is not finished

        use the top item
        increment a counter
        reinsert into pq if there is a remainder

        add the full cycle if the cycle is idle before completing

      end while
    */

    for (char c : tasks) {
      if (freq.find(c) != freq.end()) {
        freq[c]++;
      } else {
        freq[c] = 1;
      }
    }
    for (auto [_, v] : freq) {
      pq.push(v);
    }
    int res = 0;

    while (!pq.empty()) {
      int cycle = n + 1;
      vector<int> reinsert;
      while (--cycle && !pq.empty()) {
        int cur = pq.top();
        pq.pop();
        if (--cur >0) {
          reinsert.push_back(cur);
        }
      }
    }
    return res;
  }
};