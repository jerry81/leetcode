/*
264. Ugly Number II
Medium
Topics
Companies
Hint
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.



Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.


Constraints:

1 <= n <= 1690
Seen this question in a real interview before?
1/5
Yes
No
Accepted
374K
Submissions
795.8K
Acceptance Rate
47.0%
*/

class Solution {
public:
    int nthUglyNumber(int n) {

    }
};

// brute would be go thru every number and try to divide by every number to its sqrt
// think about properties
// all even numbers included in sequence
// reminds me of erasthones seive
// fill out 2x until k
// then fill out 3x until k
// finally 5x until k
// NOPE
// actually for example 16 is not allowed as 16 is divisible by 4
// 1234568
// 8 is 2 2 2  -> OK
// 14 is 2 7 - not ok