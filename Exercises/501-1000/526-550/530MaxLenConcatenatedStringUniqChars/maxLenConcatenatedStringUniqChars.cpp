/*
1239. Maximum Length of a Concatenated String with Unique Characters
Medium
Topics
Companies
Hint
You are given an array of strings arr. A string s is formed by the concatenation
of a subsequence of arr that has unique characters.

Return the maximum possible length of s.

A subsequence is an array that can be derived from another array by deleting
some or no elements without changing the order of the remaining elements.



Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers")
and "acters" ("act" + "ers"). Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.


Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
194.4K
Submissions
370.7K
Acceptance Rate
52.4%

*/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  unordered_set<int> black_list;  // combinations that are illegal
  unordered_map<int, unordered_set<char>> lookups;


 int r(unordered_set<char> curset, int idx, vector<string>& arr, int &sz) {
   if (black_list.find(idx) != black_list.end()) return r(curset, idx+1, arr, sz);

   if (idx >= sz) return 0;

   int leave = r(curset, idx+1, arr, sz);
   bool usable = true;
   unordered_set<char> nxt_set = curset;
   int count = 0;
   for (char c: lookups[idx]) {
     if (curset.find(c) != curset.end()) {
       usable=false;
       break;
     }

     nxt_set.insert(c);
     count++;
   }

   int take = (usable) ? count + r(nxt_set, idx+1,arr,sz) : 0;

   return max(take,leave);
 };

 public:
  int maxLength(vector<string>& arr) {
    int sz = arr.size();
    for (int i = 0; i < sz; ++i) {
      string s = arr[i];
      unordered_set<char> char_set;
      for (char c : s) {
        if (char_set.find(c) != char_set.end()) {
          black_list.insert(i);
          continue;
        }
        char_set.insert(c);
      }
      lookups[i] = char_set;
    }
    unordered_set<char> emp;
    return r(emp, 0, arr, sz);
  }
};