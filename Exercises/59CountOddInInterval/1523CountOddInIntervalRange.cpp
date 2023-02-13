/*

1523. Count Odd Numbers in an Interval Range
Easy
1.5K
95
Companies
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).



Example 1:

Input: low = 3, high = 7
Output: 3
Explanation: The odd numbers between 3 and 7 are [3,5,7].
Example 2:

Input: low = 8, high = 10
Output: 1
Explanation: The odd numbers between 8 and 10 are [9].


Constraints:

0 <= low <= high <= 10^9

*/
#include <iostream>

using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
       int diff = high - low;
       bool lowIsOdd = (low % 2) == 1;
       bool isOdd = (diff % 2) == 1;
       if (isOdd) {
         return diff / 2 + 1;
       } else {
         return lowIsOdd ? diff/2 + 1 : diff/2;
       }
    }
};

int main() {
  Solution s;
  int low1 = 3;
  int high1 = 7;
  cerr << "expect " << endl;
  return 0;
}