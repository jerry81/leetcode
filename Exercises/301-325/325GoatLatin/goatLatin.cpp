/*
824. Goat Latin
Easy
844
1.2K
Companies
You are given a string sentence that consist of words separated by spaces. Each
word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language
similar to Pig Latin.) The rules of Goat Latin are as follows:

If a word begins with a vowel ('a', 'e', 'i', 'o', or 'u'), append "ma" to the
end of the word. For example, the word "apple" becomes "applema". If a word
begins with a consonant (i.e., not a vowel), remove the first letter and append
it to the end, then add "ma". For example, the word "goat" becomes "oatgma". Add
one letter 'a' to the end of each word per its word index in the sentence,
starting with 1. For example, the first word gets "a" added to the end, the
second word gets "aa" added to the end, and so on. Return the final sentence
representing the conversion from sentence to Goat Latin.



Example 1:

Input: sentence = "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example 2:

Input: sentence = "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa
hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"


Constraints:

1 <= sentence.length <= 150
sentence consists of English letters and spaces.
sentence has no leading or trailing spaces.
All the words in sentence are separated by a single space.
Accepted
162.7K
Submissions
239.7K
Acceptance Rate
67.9%

*/

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  vector<string> split(string str, string delimiter) {
    // Returns first token
    vector<string> ret;
    char *token = strtok(str.data(), delimiter.c_str());

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != nullptr) {
      ret.push_back(token);
      token = strtok(nullptr, "/");
    }

    return ret;
  }

  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};

 public:
  string toGoatLatin(string sentence) {
    vector<string> spl = split(sentence, " ");
    vector<string> retV;
    for (int i = 0; i < spl.size(); ++i) {
      string w = spl[i];
      char first = w[0];
      if (vowels.find(first) != vowels.end()) {
        w += "ma";
        retV.push_back(w);
      } else {
        // swap first and last
        char tmp = w.back();
        w[w.size()-1] = first;
        w[0] = tmp;
        w+="ma";
        retV.push_back(w);
      }
    }
  }
};