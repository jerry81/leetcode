#include <string>
#include <vector>

using namespace std;

class Solution {
  bool isValidTime(int hrs, int mins) {
    return hrs <= 11 && mins <= 59;
  }

  string formatTime(int hrs, int mins) {
    string hrs_s = to_string(hrs);
    string mins_s = to_string(mins);
    if (mins_s.size() < 2) {
      mins_s = '0' + mins_s;
    }
    return hrs_s + ":" + mins_s;
  }

  void generateTimes(int turnedOn, int curHrs, int curMins, int curLED, vector<string>& res) {
    if (turnedOn == 0) {
      if (isValidTime(curHrs, curMins)) {
        res.push_back(formatTime(curHrs, curMins));
      }
      return;
    }

    for (int i = curLED; i < 10; i++) {
      if (i < 4) {
        generateTimes(turnedOn - 1, curHrs | (1 << i), curMins, i + 1, res); // Turn on LED for hours
      } else {
        generateTimes(turnedOn - 1, curHrs, curMins | (1 << (i - 4)), i + 1, res); // Turn on LED for minutes
      }
    }
  }

 public:
  vector<string> readBinaryWatch(int turnedOn) {
    vector<string> res;
    generateTimes(turnedOn, 0, 0, 0, res);
    return res;
  }
};