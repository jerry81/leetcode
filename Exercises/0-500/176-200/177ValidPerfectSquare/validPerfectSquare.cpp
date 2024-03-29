/*

367. Valid Perfect Square
Easy
3.7K
280
Companies
Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.



Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.


Constraints:

1 <= num <= 231 - 1
Accepted
491.2K
Submissions
1.1M
Acceptance Rate
43.4%

*/
class Solution {
public:
    bool isPerfectSquare(int num) {
      if (num == 1) return true;

      long long comp = num;
      long long upper = num/2;
      long long lower = 1;
      while (upper >= lower) {
        long long mid = (upper+lower)/2;
        if (mid * mid == num) return true;

        if (mid*mid > num) {
          upper = mid - 1;
        } else {
          lower = mid + 1;
        }
      }
      return false;
    }
};

// range is 1 - num/2
//