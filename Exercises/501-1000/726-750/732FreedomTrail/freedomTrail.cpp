/*

514. Freedom Trail
Hard
Topics
Companies
In the video game Fallout 4, the quest "Road to Freedom" requires players to
reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a
specific keyword to open the door.

Given a string ring that represents the code engraved on the outer ring and
another string key that represents the keyword that needs to be spelled, return
the minimum number of steps to spell all the characters in the keyword.

Initially, the first character of the ring is aligned at the "12:00" direction.
You should spell all the characters in key one by one by rotating ring clockwise
or anticlockwise to make each character of the string key aligned at the "12:00"
direction and then by pressing the center button.

At the stage of rotating the ring to spell the key character key[i]:

You can rotate the ring clockwise or anticlockwise by one place, which counts as
one step. The final purpose of the rotation is to align one of ring's characters
at the "12:00" direction, where this character must equal key[i]. If the
character key[i] has been aligned at the "12:00" direction, press the center
button to spell, which also counts as one step. After the pressing, you could
begin to spell the next character in the key (next stage). Otherwise, you have
finished all the spelling.


Example 1:


Input: ring = "godding", key = "gd"
Output: 4
Explanation:
For the first key character 'g', since it is already in place, we just need 1
step to spell this character. For the second key character 'd', we need to
rotate the ring "godding" anticlockwise by two steps to make it become
"ddinggo". Also, we need 1 more step for spelling. So the final output is 4.
Example 2:

Input: ring = "godding", key = "godding"
Output: 13


Constraints:

1 <= ring.length, key.length <= 100
ring and key consist of only lower case English letters.
It is guaranteed that key could always be spelled by rotating ring.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
41.4K
Submissions
83.9K
Acceptance Rate
49.3%
*/

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    /*
    godding
    (0)g: { g: 0, 1,  o: 1, d: 2, 3 i: 3, n: 2}
    */

    int sz = ring.size();
    vector<unordered_map<char, vector<pair<int, int>>>> lookup(sz);
    // precalc distances
    for (int i = 0; i < sz; ++i) {
      char cur = ring[i];
      int dist = 0;
      pair<int, int> pr = {dist, i};
      lookup[i][cur].push_back(pr);
      int addend = 1;
      int lower = 0;
      int upper = 0;
      while (true) {
        lower = i - addend;
        if (lower < 0) lower += sz;
        char lc = ring[lower];
        lookup[i][lc].push_back({addend, lower});
        // process lower
        if (lower == upper) break;
        upper = i + addend;
        char uc = ring[upper];
        if (upper >= sz) upper %= sz;
        if (lower == upper) break;
        // process upper
        lookup[i][uc].push_back({addend, upper});
        addend += 1;
      }
    }
    for (int i = 0; i < sz; ++i) {
      auto mp = lookup[i];
      cout << "from idx " << i << endl;
      for (auto [c, v] : mp) {
        cout << "dist to " << c << endl;
        for (auto [a, b] : v) {
          cout << a << " with idx " << b << endl;
        }
      }
    }
    return 0;
  }
};