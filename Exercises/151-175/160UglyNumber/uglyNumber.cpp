/*

263. Ugly Number
Easy
2.9K
1.5K
Companies
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.



Example 1:

Input: n = 6
Output: true
Explanation: 6 = 2 × 3
Example 2:

Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
Example 3:

Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.


Constraints:

-231 <= n <= 231 - 1
Accepted
428.5K
Submissions
1M
Acceptance Rate
42.2%

*/

#include <cmath>

using namespace std;

class Solution {
  bool isPrime(int n) {
    for (int i = 0; i <= ((int)sqrt(n)+1); ++i) {
      if (n%i == 0) return false;
    }
    return true;
  }
public:
    bool isUgly(int n) {
      for (int i = 5; i < ((int)sqrt(n)+1); i+2) {
        if (i%3 == 0) continue;

        if (i%5 == 0) continue;

        if (n%i == 0 && !isPrime(i)) return false;
      }
      return true;
    }
};

// hmm..
/*
  try all primes?
  directly get factors and check primeness
*/