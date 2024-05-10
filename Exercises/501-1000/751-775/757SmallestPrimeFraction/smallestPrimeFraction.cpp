/*

786. K-th Smallest Prime Fraction
Medium
Topics
Companies
You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].



Example 1:

Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
Example 2:

Input: arr = [1,7], k = 1
Output: [1,7]


Constraints:

2 <= arr.length <= 1000
1 <= arr[i] <= 3 * 104
arr[0] == 1
arr[i] is a prime number for i > 0.
All the numbers of arr are unique and sorted in strictly increasing order.
1 <= k <= arr.length * (arr.length - 1) / 2


Follow up: Can you solve the problem with better than O(n2) complexity?
Seen this question in a real interview before?
1/5
Yes
No
Accepted
87.4K
Submissions
138.5K
Acceptance Rate
63.1%

*/

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Create a priority queue to store pairs of fractions
        priority_queue<pair<double, pair<int, int>>> pq;

        // Push the fractions formed by dividing each element by
        // the largest element into the priority queue
        for (int i = 0; i < arr.size(); i++)
            pq.push({-1.0 * arr[i] / arr.back(), {i, arr.size() - 1}});

        // Iteratively remove the top element (smallest fraction)
        // and replace it with the next smallest fraction
        while (--k > 0) {
            pair<int, int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0 * arr[cur.first] / arr[cur.second],
                    {cur.first, cur.second}});
        }

        // Retrieve the kth smallest fraction from
        // the top of the priority queue
        pair<int, int> result = pq.top().second;
        return {arr[result.first], arr[result.second]};
    }
};