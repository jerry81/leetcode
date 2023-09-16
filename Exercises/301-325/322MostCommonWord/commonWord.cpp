/*

819. Most Common Word
Easy
1.6K
3K
Companies
Given a string paragraph and a string array of the banned words banned, return
the most frequent word that is not banned. It is guaranteed there is at least
one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in
lowercase.



Example 1:

Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.",
banned = ["hit"] Output: "ball" Explanation: "hit" occurs 3 times, but it is a
banned word. "ball" occurs twice (and no other word does), so it is the most
frequent non-banned word in the paragraph. Note that words in the paragraph are
not case sensitive, that punctuation is ignored (even if adjacent to words, such
as "ball,"), and that "hit" isn't the answer even though it occurs more because
it is banned. Example 2:

Input: paragraph = "a.", banned = []
Output: "a"


Constraints:

1 <= paragraph.length <= 1000
paragraph consists of English letters, space ' ', or one of the symbols:
"!?',;.". 0 <= banned.length <= 100 1 <= banned[i].length <= 10 banned[i]
consists of only lowercase English letters. Accepted 333.4K Submissions 749.2K
Acceptance Rate
44.5%

*/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> freq;
    unordered_set<string> b;
    string res = "";
    int mx = 0;
    for (string s : banned) b.insert(s);
    string cur = "";
    for (char c : paragraph) {
      if (c == ' ') {
        if (b.find(cur) != b.end()) {
          freq[cur]++;
          if (freq[cur] > mx) {
            mx = freq[cur];
            res = cur;
          }
        }
        cur = "";
      }
    }
    return res;
  }
};