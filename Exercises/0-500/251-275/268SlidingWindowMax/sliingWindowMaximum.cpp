/*

239. Sliding Window Maximum
Hard
15.6K
516
Companies
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
Accepted
812.5K
Submissions
1.8M
Acceptance Rate
46.2%

*/

#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      vector<int> ret;
      deque<int> cache;
      // establish sliding window
      // go from 0 to k-1
      for (int i = 0; i < k; ++i) {
        if (cache.empty()) {
          cache.push_back(i);
          continue;
        }

        int curnum = nums[i];

        if (nums[cache.front()] < curnum) {
          cache.clear();
          cache.push_back(i);
          continue;
        }

        while (!cache.empty() && curnum > nums[cache.back()]) {
          cache.pop_back();
        }

        cache.push_back(i);
      }
      // record first result
      ret.push_back(nums[cache.front()]);
      int stop = nums.size() - k;
      // move sliding window to end
      for (int i = 1; i <= stop; ++i) {
        if (cache.front() < i) {
          cache.pop_front();
        }

        int endIdx = i+k-1;

        int curnum = nums[endIdx];

        if (cache.empty()) {
          cache.push_back(endIdx);
          ret.push_back(nums[cache.back()]);
          continue;
        }

        if (curnum > nums[cache.front()]) {
          cache.clear();
          cache.push_back(endIdx);
          ret.push_back(nums[cache.front()]);
          continue;
        }

        while (!cache.empty() && curnum > nums[cache.back()]) {
          cache.pop_back();
        }

        cache.push_back(endIdx);

        ret.push_back(nums[cache.front()]);
      }
      return ret;
    }
};
/*

issue - sliding window on each step removes one item and adds one item
pq doesn't do well with popping anything but min/max
if we maintain our own sorted list
then each operation will require searching for the dropped item and inserting the added item
we can first check if the max was dropped and if the newly added item becomes the new max?
what if max just naturally "dies" and a new replacement is not found yet?
then we rely on sorted list still or rediscover the max

*/

/*

official
1 (only solution):  monotonic deque
  - monotonic means increasing or decreasing
  - can ignore items with index lower than current max
    - discared them
*/

/*

deque data structure
double-ended queue
  - unlike traditional - add to back and remove from front
  - can insert and remove from both front and rear

#include <deque>

    std::deque<int> myDeque;

    // Adding elements
    myDeque.push_back(10);   // Add 10 to the rear
    myDeque.push_front(5);   // Add 5 to the front

    // Removing elements
    int frontElement = myDeque.front(); // Get the front element (5)
    int rearElement = myDeque.back();   // Get the rear element (10)
    myDeque.pop_front();  // Remove the front element
    myDeque.pop_back();   // Remove the rear element

    // Accessing elements
    int firstElement = myDeque[0];  // Access the front element
    int lastElement = myDeque.back();  // Access the rear element

    return 0;
*/