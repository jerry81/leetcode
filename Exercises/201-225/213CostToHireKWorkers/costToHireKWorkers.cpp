/*

2462. Total Cost to Hire K Workers
Medium
562
119
Companies
You are given a 0-indexed integer array costs where costs[i] is the cost of
hiring the ith worker.

You are also given two integers k and candidates. We want to hire exactly k
workers according to the following rules:

You will run k sessions and hire exactly one worker in each session.
In each hiring session, choose the worker with the lowest cost from either the
first candidates workers or the last candidates workers. Break the tie by the
smallest index. For example, if costs = [3,2,7,7,1,2] and candidates = 2, then
in the first hiring session, we will choose the 4th worker because they have the
lowest cost [3,2,7,7,1,2]. In the second hiring session, we will choose 1st
worker because they have the same lowest cost as 4th worker but they have the
smallest index [3,2,7,7,2]. Please note that the indexing may be changed in the
process. If there are fewer than candidates workers remaining, choose the worker
with the lowest cost among them. Break the tie by the smallest index. A worker
can only be chosen once. Return the total cost to hire exactly k workers.



Example 1:

Input: costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4
Output: 11
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [17,12,10,2,7,2,11,20,8].
The lowest cost is 2, and we break the tie by the smallest index, which is 3.
The total cost = 0 + 2 = 2.
- In the second hiring round we choose the worker from [17,12,10,7,2,11,20,8].
The lowest cost is 2 (index 4). The total cost = 2 + 2 = 4.
- In the third hiring round we choose the worker from [17,12,10,7,11,20,8]. The
lowest cost is 7 (index 3). The total cost = 4 + 7 = 11. Notice that the worker
with index 3 was common in the first and last four workers. The total hiring
cost is 11. Example 2:

Input: costs = [1,2,4,1], k = 3, candidates = 3
Output: 4
Explanation: We hire 3 workers in total. The total cost is initially 0.
- In the first hiring round we choose the worker from [1,2,4,1]. The lowest cost
is 1, and we break the tie by the smallest index, which is 0. The total cost = 0
+ 1 = 1. Notice that workers with index 1 and 2 are common in the first and last
3 workers.
- In the second hiring round we choose the worker from [2,4,1]. The lowest cost
is 1 (index 2). The total cost = 1 + 1 = 2.
- In the third hiring round there are less than three candidates. We choose the
worker from the remaining workers [2,4]. The lowest cost is 2 (index 0). The
total cost = 2 + 2 = 4. The total hiring cost is 4.


Constraints:

1 <= costs.length <= 105
1 <= costs[i] <= 105
1 <= k, candidates <= costs.length
Accepted
19.7K
Submissions
49.9K
Acceptance Rate
39.5%

*/

#include <queue>
#include <vector>

using namespace std;

class Solution {

  struct VandI {
    int val;
    int idx;
    VandI(int val, int idx):val(val),idx(idx){};
  };

  struct ComparePQ {
    bool operator()(VandI a, VandI b) {
      if (a.val < b.val) {
        return true;
      } else if (a.val > b.val) {
        return true;
      } else {
        return a.idx < b.idx;
      }
    }  // this is idiomatic...
  };

 public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    priority_queue<VandI, vector<VandI>, ComparePQ> left;  // type of data, container impl, comparator
    priority_queue<VandI, vector<VandI>, ComparePQ> right;
    // prep pqs
    int benchLeft = 1;
    int benchRight = costs.size()-2;
    long long total = 0;
    for (int i = 0; i < candidates; ++i) {
      if (i >= costs.size()) break;

      left.push(VandI(costs[i],i));
      benchLeft = i+1;
    }
    if (left.size() == candidates) {
      for (int i = costs.size()-1; i >= candidates; --i) {
        right.push(VandI(costs[i],i));
        benchRight = i-1;
      }
    }
    // loop k times
    for (int i = 0; i < k; ++i) {
     if (right.empty()) {
       total+=left.top().val;
       left.pop();
       continue;
     }

     if (left.empty()) {
       total+=right.top().val;
       right.pop();
       continue;
     }

     auto lmin = left.top();
     auto rmin = right.top();
     if (lmin.val <= rmin.val) {
       total+=lmin.val;
       left.pop();
       if (benchLeft <= benchRight) {
         left.push(VandI(costs[benchLeft], benchLeft));
         benchLeft++;
       }
     } else {
       total+=rmin.val;
       right.pop();
       if (benchLeft <= benchRight) {
         right.push(VandI(costs[benchRight], benchRight));
         benchRight--;
       }
     }
    }

    return total;
  }
};

/*

analysis:  too straightforward to not  be an optimization trap

cost [1,2,4,1], candidates 3, k 3
expect 4

124 241
-> 241
24
2
total cost 4


costs = [17,12,10,2,7,2,11,20,8], k = 3, candidates = 4 - expect 11
17,12,10,7,2,11,20,8 cost 2
17,12,10,7,11,20,8 cost 4
                   cost 11 yes

brute force - calc min twice each round
vector always shrinking
[0,3] [5,8] (min in left) - picked = 3
- shift from picked left
[0,3] [4,7] but 4,7 same as 5,8 in previous step

or
pq good here
[17,12,10,2] [7] (benchLeft=4, benchRight = 4)  [2,11,20,8]  - bench

dequeue
then insert from bench
[17,12,10,7] [] [2,11,20,8]

dequeue
[17,12,10,7] [11,20,8]


left changed but right manages to still be the same


*/