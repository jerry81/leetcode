/*

1845. Seat Reservation Manager
Medium
714
44
Companies
Design a system that manages the reservation state of n seats that are numbered
from 1 to n.

Implement the SeatManager class:

SeatManager(int n) Initializes a SeatManager object that will manage n seats
numbered from 1 to n. All seats are initially available. int reserve() Fetches
the smallest-numbered unreserved seat, reserves it, and returns its number. void
unreserve(int seatNumber) Unreserves the seat with the given seatNumber.


Example 1:

Input
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve",
"reserve", "reserve", "unreserve"]
[[5], [], [], [2], [], [], [], [], [5]]
Output
[null, 1, 2, null, 2, 3, 4, 5, null]

Explanation
SeatManager seatManager = new SeatManager(5); // Initializes a SeatManager with
5 seats. seatManager.reserve();    // All seats are available, so return the
lowest numbered seat, which is 1. seatManager.reserve();    // The available
seats are [2,3,4,5], so return the lowest of them, which is 2.
seatManager.unreserve(2); // Unreserve seat 2, so now the available seats are
[2,3,4,5]. seatManager.reserve();    // The available seats are [2,3,4,5], so
return the lowest of them, which is 2. seatManager.reserve();    // The
available seats are [3,4,5], so return the lowest of them, which is 3.
seatManager.reserve();    // The available seats are [4,5], so return the lowest
of them, which is 4. seatManager.reserve();    // The only available seat is
seat 5, so return 5. seatManager.unreserve(5); // Unreserve seat 5, so now the
available seats are [5].


Constraints:

1 <= n <= 105
1 <= seatNumber <= n
For each call to reserve, it is guaranteed that there will be at least one
unreserved seat. For each call to unreserve, it is guaranteed that seatNumber
will be reserved. At most 105 calls in total will be made to reserve and
unreserve. Accepted 44.6K Submissions 65.3K Acceptance Rate 68.4%

*/

#include <queue>

using namespace std;

struct ComparePQ {
  bool operator()(int a, int b) { return a < b; }
};
class SeatManager {
  int sz;
  int nxt = 0;
  priority_queue<int, vector<int>, ComparePQ> holes;

 public:
  SeatManager(int n) { sz = n; }

  int reserve() {
    if (holes.empty()) return ++nxt;

    int ret = holes.top();
    holes.pop();
    return ret;
  }

  void unreserve(int seatNumber) {
    holes.push(seatNumber);
  }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */