/*

648. Replace Words
Medium
Topics
Companies
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.



Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"


Constraints:

1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] consists of only lower-case letters.
1 <= sentence.length <= 106
sentence consists of only lower-case letters and spaces.
The number of words in sentence is in the range [1, 1000]
The length of each word in sentence is in the range [1, 1000]
Every two consecutive words in sentence will be separated by exactly one space.
sentence does not have leading or trailing spaces.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
178.6K
Submissions
274.7K
Acceptance Rate
65.0%

*/

#include <string>
#include <vector>

using namespace std;

bool compareByLength(const std::string &a, const std::string &b) {
    return a.size() < b.size();
}


vector<string> split(string str, string delimiter) {
  // Returns first token
  vector<string> ret;
  const char *del = delimiter.c_str();
  char *token = strtok(str.data(), del);

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != nullptr) {
    ret.push_back(token);
    token = strtok(nullptr,del);
  }

  return ret;
}
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // sort the roots by len
        // try starts_with on roots
        vector<string> sorted = dictionary;
        sort(sorted.begin(), sorted.end(), compareByLength);
        vector<string> spl = split(sentence, " ");
        string res = "";

        for (string s: spl) {
          bool found = false;
          string appended = s;
          for (string s2: sorted) {
            if (s.find(s2)==0) {
              found = true;
              appended = s2;
              break;
            }
          }
          res+=appended;
          res+=" ";
        }
        res.pop_back();
        return res;
    }
};