/*

401. Binary Watch
Easy
1.2K
2.2K
Companies
A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.

For example, the below binary watch reads "4:51".


Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

The hour must not contain a leading zero.

For example, "01:00" is not valid. It should be "1:00".
The minute must be consist of two digits and may contain a leading zero.

For example, "10:2" is not valid. It should be "10:02".


Example 1:

Input: turnedOn = 1
Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
Example 2:

Input: turnedOn = 9
Output: []


Constraints:

0 <= turnedOn <= 10
Accepted
126.9K
Submissions
241.3K
Acceptance Rate
52.6%

*/

#include <vector>
#include <string>

using namespace std;

class Solution {

bool valid(string s) {
  string hrs = s.substr(0, 4);
  string mins = s.substr(4);
  int hrsi = stoi(hrs, 0, 2);
  int minsi = stoi(mins, 0, 2);
  if (hrsi > 12) return false;

  if (minsi > 60) return false;

  return true;
}

void r(string curS, int toUse, vector<string>& res) {
  if (curS.size() > 10) return;

  if (toUse == 0) {

  }
}

public:
    vector<string> readBinaryWatch(int turnedOn) {
      // 4 for hour
      // 6 for minutes
      // try every possible hour and minute combo
      vector<string> ret;
      if (turnedOn >= 9) return ret;

      r("", turnedOn, ret);

      return ret;
    }
};

// go thru possibilities with tree-like recursion
// r(string curTime, toUse)