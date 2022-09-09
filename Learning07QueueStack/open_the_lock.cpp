/*
Open the Lock

Solution
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.



Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".
Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.


Constraints:

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
*/

#include <iostream>
#include <vector> // make modules available, CLASSPATH in java
#include <queue>
#include <unordered_map>

using namespace std; // saves us from prepending std:: corresponds to "import" in java

class Solution
{
  unordered_map<string, bool> lookup;

private:
  string incrAt(string input, char idx, bool decrement = false)
  {
    string copy = input;
    int x = copy[idx] - '0';
    int n_x = decrement ? x - 1 : x + 1;
    if (n_x < 0)
      n_x = 9;
    copy[idx] = n_x % 10 + '0';
    return copy;
  }

  vector<string> bfs(vector<string> current)
  {
    vector<string> nxt;
    for (string c : current)
    {
      for (int i = 0; i < 4; ++i)
      {
        string neighbor = incrAt(c, i);
        string d_neighbor = incrAt(c, i, true);
        if (!lookup[neighbor])
        {
          lookup[neighbor] = true;
          nxt.push_back(neighbor);
          if (neighbor == "0000") { // string compare in c++
            nxt.clear();
            nxt.push_back("0000");
            return nxt;
          }
        }
      }
    }
    return nxt;
  }

public:
  int openLock(vector<string> &deadends, string target)
  {
    for (string deadend : deadends)
    {
      lookup[deadend] = true;
    }
    vector<string> start;
    start.push_back(target);
    lookup[target] = true;
    int count = 1;
    while (start.size() > 0) {
      start = bfs(start);
      if (start.front()== "0000") return count;
      count++;
    }
    return -1;
    // move from target to 0000
    // string s="0000";
    // string t = incrAt(s, 3, true);
    // cerr << "t is now "<<t<<endl;
    // cerr<<"s is now "<<s<<endl;
  }
};

int main()
{
  Solution s;
  vector<string> deadends;
  deadends.push_back("0201");
  deadends.push_back("0101");
  deadends.push_back("0102");
  deadends.push_back("1212");
  deadends.push_back("2002");
  int res = s.openLock(deadends, "0202");
  cerr << "res is "<< res<<endl;
  return 0;
}

// hashmap in c++
// can use <map> or <unordered_map>
// unordered map is O(1) map is O(log n)