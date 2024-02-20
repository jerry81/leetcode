/*


For two strings s and t, we say "t divides s" if and only if s = t + ... + t
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides
both str1 and str2.



Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""


Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.

*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    string longest = "";
    for (int i = 1; i <= str1.length(); ++i) {
      string prefix = str1.substr(0, i);
      string t1 = removeSubstrings(prefix, str1);
      string t2 = removeSubstrings(prefix, str2);
      if (t1.empty() && t2.empty()) {
        longest = prefix;
      }
    }

    return longest;
    // for each prefix string in the shorter string, use regex to match away
    // every substring on both, if they both end up as empty strings, return
    // that prefix
  }

  string removeSubstrings(string sub, string orig) {
    int l = sub.length();
    string res = orig;
    for (auto i = res.find(sub); i != string::npos; i = res.find(sub)) {
      res.erase(i, l);
    }
    return res;
  }
};

int main() {
  string s1 = "ABCABC";
  string s2 = "ABC";
  Solution s;
  cerr << "expect ABC: " << s.gcdOfStrings(s1, s2) << endl;
  cerr << "expect nothing: " << s.removeSubstrings(s2, s1) << endl;
  return 0;
}

/* reference code from oreilly

#include <iostream>
#include <string>

using namespace std;

template<typename T>
void removeSubstrs(basic_string<T>& s,
                   const basic_string<T>& p) {
   basic_string<T>::size_type n = p.length();

   for (basic_string<T>::size_type i = s.find(p);
        i != basic_string<T>::npos;
        i = s.find(p))
      s.erase(i, n);
}

int main() {
   string s = "One fish, two fish, red fish, blue fish";
   string p = "fish";

   removeSubstrs(s, p);

   cout << s << '\n';
}

*/