/*

839. Similar String Groups
Hard
1.1K
184
Companies
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?



Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1


Constraints:

1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.
Accepted
67.5K
Submissions
138.6K
Acceptance Rate
48.7%

*/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool areSimilar(string s1, string s2) {
  string o1 = s1;
  for (int i = 0; i < s1.size()-1; ++i) {
    for (int j = i+1; j < s1.size(); ++j) {
      char temp = s1[j];
      s1[j] = s1[i];
      s1[i] = temp;
      if (s1 == s2) return true;

      s1=o1;
    }
  }
  return false;
}
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
      for (int i = 0; i < strs.size()-1; ++i) {
        for (int j = i+1; j < strs.size(); ++j) {
          cout << strs[i] << " and " << strs[j] << " are " << areSimilar(strs[i], strs[j]) << endl;;
        }
      }
      return 0;
    }
};

// go naive
// similar helper