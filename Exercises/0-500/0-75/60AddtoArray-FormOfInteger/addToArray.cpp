/*

989. Add to Array-Form of Integer
Easy
2K
185
Companies
The array-form of an integer num is an array representing its digits in left to
right order.

For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form
of the integer num + k.



Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
Example 2:

Input: num = [2,7,4], k = 181
Output: [4,5,5]
Explanation: 274 + 181 = 455
Example 3:

Input: num = [2,1,5], k = 806
Output: [1,0,2,1]
Explanation: 215 + 806 = 1021


Constraints:

1 <= num.length <= 104
0 <= num[i] <= 9
num does not contain any leading zeros except for the zero itself.
1 <= k <= 104
Accepted
158.9K
Submissions
343.8K
Acceptance Rate
46.2%

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    // use long addition

    vector<int> ret;
    string asS = to_string(k);
    bool carry = false;
    for (int i = 0; i < asS.size(); ++i) {
      int curD = asS[asS.size() - i - 1] - '0';
      int oIdx = num.size() - i - 1;
      if (oIdx < 0) {
        int sum = curD + carry;
        if (sum >= 10) {
          sum -= 10;
          carry = true;
          ret.push_back(sum);
          continue;
        } else {
          ret.push_back(sum);
          carry = false;
          continue;
        }
      }
      int curSum = num[oIdx] + curD + carry;
      if (curSum >= 10) {
        int partialSum = curSum - 10;
        ret.push_back(partialSum);
        carry = true;
      } else {
        ret.push_back(curSum);
        carry = false;
      }
    }
    for (int i = asS.size(); i < num.size(); ++i) {
      int oIdx = num.size() - i - 1;
      int curSum = num[oIdx] + carry;
      if (curSum >= 10) {
        int partialSum = curSum - 10;
        ret.push_back(partialSum);
        carry = true;
      } else {
        ret.push_back(curSum);
        carry = false;
      }
    }
    if (carry) ret.push_back(1);
    reverse(ret.begin(), ret.end());
    return ret;
  }
};

int main() {
  Solution s;
  vector<int> test1;
  test1 = {1, 2, 0, 0};
  s.addToArrayForm(test1, 34);
  vector<int> test2;
  test2 = {};
  vector<int> result = s.addToArrayForm(test2, 23);
  for (int i : result) {
    cerr << "i is " << i << endl;
  }
  vector<int> test3;
  test3 = {9, 9, 3};
  result = s.addToArrayForm(test3, 7);
  for (int i : result) {
    cerr << "i is " << i << endl;
  }
  return 0;
}