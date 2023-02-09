/*

2306. Naming a Company
Hard
450
27
Companies
You are given an array of strings ideas that represents a list of names to be used in the process of naming a company. The process of naming a company is as follows:

Choose 2 distinct names from ideas, call them ideaA and ideaB.
Swap the first letters of ideaA and ideaB with each other.
If both of the new names are not found in the original ideas, then the name ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is a valid company name.
Otherwise, it is not a valid name.
Return the number of distinct valid names for the company.



Example 1:

Input: ideas = ["coffee","donuts","time","toffee"]
Output: 6
Explanation: The following selections are valid:
- ("coffee", "donuts"): The company name created is "doffee conuts".
- ("donuts", "coffee"): The company name created is "conuts doffee".
- ("donuts", "time"): The company name created is "tonuts dime".
- ("donuts", "toffee"): The company name created is "tonuts doffee".
- ("time", "donuts"): The company name created is "dime tonuts".
- ("toffee", "donuts"): The company name created is "doffee tonuts".
Therefore, there are a total of 6 distinct company names.

The following are some examples of invalid selections:
- ("coffee", "time"): The name "toffee" formed after swapping already exists in the original array.
- ("time", "toffee"): Both names are still the same after swapping and exist in the original array.
- ("coffee", "toffee"): Both names formed after swapping already exist in the original array.
Example 2:

Input: ideas = ["lack","back"]
Output: 0
Explanation: There are no valid selections. Therefore, 0 is returned.


Constraints:

2 <= ideas.length <= 5 * 104
1 <= ideas[i].length <= 10
ideas[i] consists of lowercase English letters.
All the strings in ideas are unique.
Accepted
10.8K
Submissions
29.1K
Acceptance Rate
37.1%

*/

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Swapped {
  string word1 = "";
  string word2 = "";
};

class Solution {
unordered_map<string, bool> lookup;

bool lc(string key) { //lookup contains helper
  return (lookup.find(key) != lookup.end());
}

Swapped swapFirst(string s1, string s2) {
  string temp = s1;
  s1[0] = s2[0];
  s2[0] = temp[0];
  Swapped sw;
  sw.word1 = s1;
  sw.word2 = s2;
  return sw;
}

bool sameFirst(string s1, string s2) {
  return s1[0] == s2[0];
}

bool canAdd(Swapped inp) {
  return (!lc(inp.word1) && !lc(inp.word2));
}

public:
    long long distinctNames(vector<string>& ideas) {
      long long count = 0;
      for (string s: ideas) {
        lookup[s] = true;
      }
      for (int i = 0; i < (ideas.size()-1); ++i) {
        string item1 = ideas[i];
        for (int j = i+1; j < ideas.size(); ++j) {
          string item2 = ideas[j];
          if (sameFirst(item1, item2)) continue;

          Swapped res = swapFirst(item1, item2);
          if (canAdd(res)) count+=2;
        }
      }
      return count;
    }
};