/*
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to
wait after the ith day to get a warmer temperature. If there is no future day
for which this is possible, keep answer[i] == 0 instead.



Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]


Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

If the temperature is say, 70 today, then in the future a warmer temperature
must be either 71, 72, 73, ..., 99, or 100. We could remember when all of them
occur next.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    size_t size = temperatures.size();
    cerr << "size is " << size << endl;
    // work backwards
    // unordered map of indexes: temps
    // write index
    int arr[size];
    int lookup[size];
    vector<int> sol;
    for (int i = (size - 1); i > -1; --i) {
      int temp = temperatures.back();
      temperatures.pop_back();
      lookup[i] = temp;
      arr[i] = 0;

      for (int j = i; j < size; ++j) {
        int cmp = lookup[j];
        if (temp < cmp) {
          cerr << "j-i " << j - i << endl;
          arr[i] = j - i;
        }
      }
    }
    for (int i = 0; i < size; ++i) {
      sol.push_back(arr[i]);
    }

    return sol;
  }
};

int main() {
  Solution s;
  vector<int> t;
  t.push_back(73);
  t.push_back(74);
  t.push_back(75);

  t.push_back(71);

  t.push_back(69);
  t.push_back(72);
  t.push_back(76);
  t.push_back(73);

  vector<int> sol = s.dailyTemperatures(t);
  for (int s : sol) {
    cerr << "s is " << s << endl;
  }
  return 0;
}