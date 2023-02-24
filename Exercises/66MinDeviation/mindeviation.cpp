/*
1675. Minimize Deviation in Array
Hard
1.9K
105
Companies
You are given an array nums of n positive integers.

You can perform two types of operations on any element of the array any number
of times:

If the element is even, divide it by 2.
For example, if the array is [1,2,3,4], then you can do this operation on the
last element, and the array will be [1,2,3,2]. If the element is odd, multiply
it by 2. For example, if the array is [1,2,3,4], then you can do this operation
on the first element, and the array will be [2,2,3,4]. The deviation of the
array is the maximum difference between any two elements in the array.

Return the minimum deviation the array can have after performing some number of
operations.



Example 1:

Input: nums = [1,2,3,4]
Output: 1
Explanation: You can transform the array to [1,2,3,2], then to [2,2,3,2], then
the deviation will be 3 - 2 = 1. Example 2:

Input: nums = [4,1,5,20,3]
Output: 3
Explanation: You can transform the array after two operations to [4,2,5,5,3],
then the deviation will be 5 - 2 = 3. Example 3:

Input: nums = [2,10,8]
Output: 3


Constraints:

n == nums.length
2 <= n <= 5 * 104
1 <= nums[i] <= 109
Accepted
52.5K
Submissions
99.4K
Acceptance Rate
52.8%

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
  struct CompareMinPQ {
    bool operator()(int a, int b) { return a > b; }
  };
  struct CompareMaxPQ {
    bool operator()(int a, int b) { return a < b; }
  };

 public:
  int minimumDeviation(vector<int>& nums) {
    // ideas:
    // min heap, maxheap
    // deviation is difference between max and min
    priority_queue<int, vector<int>, CompareMinPQ> minpq;
    priority_queue<int, vector<int>, CompareMaxPQ> maxpq;
    for (int i:nums) {
      minpq.push(i);
      maxpq.push(i);
    }
    int max = maxpq.top();
    int min = minpq.top();
    while ((max % 2) == 0) {
      int newMax = max / 2;
      maxpq.pop();
      maxpq.push(newMax);
      max = maxpq.top();
    }
    while ((min%2) == 1) {
      int newMin = min*2;
      minpq.pop();
      minpq.push(newMin);
      min = minpq.top();
    }
    return maxpq.top() - minpq.top();
    }
};

int main() {
  Solution s;
  vector<int> test1 = {1, 2, 3, 4};
  cerr << "expect 1 " << s.minimumDeviation(test1) << endl;
  vector<int> test2 = {4, 1, 5, 20, 3};
  cerr << "expect 3 " << s.minimumDeviation(test2) << endl;
  vector<int> test3 = {2, 10, 8};
  cerr << "expect 3 " << s.minimumDeviation(test3) << endl;
  return 0;
}

// 2,10,8
// 2,5,4