/*

68. Text Justification
Hard
2.5K
3.7K
Companies
Given an array of strings words and a width maxWidth, format the text such that
each line has exactly maxWidth characters and is fully (left and right)
justified.

You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line does not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is
inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters
only. Each word's length is guaranteed to be greater than 0 and not exceed
maxWidth. The input array words contains at least one word.


Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."],
maxWidth = 16 Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall be",
because the last line must be left-justified instead of fully-justified. Note
that the second line is also left-justified because it contains only one word.
Example 3:

Input: words =
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],
maxWidth = 20 Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]


Constraints:

1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
Accepted
310.6K
Submissions
805.3K
Acceptance Rate
38.6%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
  pair<int, int> calcNextStop(int curWordI, vector<string>& words,
                              int maxWidth) {
    int numWords = 0;
    int curLen = 0;
    int totalWordLen = 0;
    int modifier = 0;
    while (words[curWordI].size() + curLen + modifier <= maxWidth) {
      numWords++;
      totalWordLen += words[curWordI].size();
      curLen = totalWordLen + max(0, numWords - 1);
      modifier = 1;

      curWordI++;
      if (curWordI >= words.size()) break;
    }
    int extraSpaces = maxWidth - totalWordLen;
    return {curWordI, extraSpaces};
  }

 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int curwordI = 0;
    vector<string> ret;
    // try to fit words in line
    // at least one space
    while (curwordI < words.size()) {
      auto [nextStop, spaces] = calcNextStop(curwordI, words, maxWidth);
      int numwords = nextStop - curwordI;
      int perGap = numwords > 1 ? spaces / (numwords - 1)
                                : spaces - max(0, numwords - 1);
      int calculatedSpaces = perGap * (numwords - 1);
      int diff = 0;
      if (calculatedSpaces < spaces) {
        diff = spaces - calculatedSpaces;
      }
      string curString = "";
      string gap = string(perGap, ' ');
      if (numwords == 1) {
        curString += words[curwordI];
        while (curString.size() < maxWidth) {
          curString += ' ';
        }
      } else if (nextStop >= words.size()) {
        for (int i = curwordI; i < words.size(); ++i) {
          curString += words[i];
          if (i == nextStop - 1) {
            while (curString.size() < maxWidth) {
              curString += ' ';
            }
          } else {
            curString += ' ';
          }
        }
      } else {
        for (int i = curwordI; i < nextStop; ++i) {
          curString += words[i];
          if (i < nextStop - 1) {
            curString += gap;
            if (diff > 0) {
              curString += ' ';
              diff--;
            }
          }
        }
      }
      ret.push_back(curString);
      curwordI = nextStop;
    }

    return ret;
  }
};

// wtf mate, lets jump straight to official sol
/*
  ha, no algorithmic tricks required

["Science is what we","understand      well","enough to explain to","a computer.
Art is","everything  else  we","do                  "]
["Science  is  what we","understand      well","enough to explain to","a
computer.  Art is","everything  else  we","do                  "]
*/