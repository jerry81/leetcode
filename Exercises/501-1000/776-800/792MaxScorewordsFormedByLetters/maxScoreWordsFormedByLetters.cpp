/*

1255. Maximum Score Words Formed by Letters
Hard
Topics
Companies
Hint
Given a list of words, list of  single letters (might be repeating) and score of
every character.

Return the maximum score of any valid set of words formed by using the given
letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be
used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0],
score[1], ... , score[25] respectively.



Example 1:

Input: words = ["dog","cat","dad","good"], letters =
["a","a","c","d","d","d","g","o","o"], score =
[1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0] Output: 23 Explanation:
Score  a=1, c=9, d=5, g=3, o=2
Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a
score of 23. Words "dad" and "dog" only get a score of 21. Example 2:

Input: words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"],
score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10] Output: 27
Explanation:
Score  a=4, b=4, c=4, x=5, z=10
Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5) with
a score of 27. Word "xxxz" only get a score of 25. Example 3:

Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score =
[0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0] Output: 0 Explanation:
Letter "e" can only be used once.


Constraints:

1 <= words.length <= 14
1 <= words[i].length <= 15
1 <= letters.length <= 100
letters[i].length == 1
score.length == 26
0 <= score[i] <= 10
words[i], letters[i] contains only lower case English letters.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
44.7K
Submissions
59.8K
Acceptance Rate
74.8%

*/

#include <string>
#include <vector>

using namespace std;

class Solution {
 int r(int idx, vector<int> &freq, vector<vector<int>> &word_freqs, vector<int> &word_scores, int sz) {
  // base case
  if (idx >= sz) return 0;
  // leave the word

  int nxt = idx+1;
  int leave = r(nxt, freq, word_freqs, word_scores, sz);
  // take the word
  vector<int> cur_freq = word_freqs[idx];
  int cur_score = word_scores[idx];
  int take = leave;
  bool can_include = true;
  for (int i = 0; i < 26; ++i) {
    int new_freq = freq[i] - cur_freq[i];
    if (cur_freq[i] > freq[i]) {
      can_include = false; // abort + rollback
      break;
    }
  }
  if (can_include) {
    for (int i = 0; i < 26; ++i) {
      freq[i] -= cur_freq[i];
    }
    take = cur_score + r(nxt, freq, word_freqs, word_scores, sz);
    for (int i = 0; i < 26; ++i) {
      freq[i] += cur_freq[i];
    }
  }

  // backtrack
  return max(take, leave);
 }
 public:
  int maxScoreWords(vector<string>& words, vector<char>& letters,
                    vector<int>& score) {
    // score is score[char - 'a']
    // unordered_map for chars remaining
    vector<int> freq(26, 0);
    for (char c : letters) {
      freq[c - 'a']++;
    }
    // map for each word?
    int word_sz = words.size();
    vector<vector<int>> word_freq(word_sz, vector<int>(26,0));
    vector<int> word_scores(word_sz,0);
    for (int i = 0; i < word_sz; ++i) {
      for (char c : words[i]) {
        word_freq[i][c - 'a']++;
        word_scores[i]+=score[c-'a'];
      }
    }
    // order words by value and greedy?
    // no, long words more costly

    // stick recursion with backtracking theme

    return r(0, freq, word_freq,word_scores,word_sz);
  }
};