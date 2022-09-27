/*
Decode String

Solution
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.



Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"


Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/
#include <string>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;
class Solution {
public:
    string decodeString(string s) {
      queue<string> substrings;
      stack<string> items;
      for (auto &ch : s) { // auto allows type to be deduced from initializer
        string as_s(1,ch);
        if (ch == '\0') cout << "null printed " << endl;
        items.push(as_s);
        if (ch == ']') {
          stack<string> subs;
          items.pop();
          string cur = items.top();
          while (cur != "[") {
            if (cur != "[") {
              subs.push(cur);
            }
            items.pop();
            cur = items.top();
          }

          string rev = "";
          while (!subs.empty()) {
            rev+=subs.top();
            subs.pop();
          }
          items.pop();
          string strang = "";
          // here we should loop until we hit a non-digit
          int count = items.top()[0] - '0';
          items.pop(); // remove the number
          while (count > 0) {
            --count;
            strang+=rev;
            cout << "strang is now " << strang << endl;
          }
          substrings.push(strang);
          items.push(strang);
          cout << "pushed to items: " << strang << endl;
        }
      }
      stack<string> reved;
      while (!items.empty()) {
        string next = items.top();
        cout << "next item is " << next << endl;
        items.pop();
        reved.push(next);
      }
      string output = "";
      while (!reved.empty()) {
        string next = reved.top();
        cout << "next reved is " << next << endl;
        reved.pop();
        output+=next;
      }

      // while (!substrings.empty()) {
      //   string next = substrings.front();
      //   output += next;
      //   cout << "next is " << next << endl;
      //   substrings.pop();
      // }

      return output;
    }
};

int main() {
  Solution s = Solution();
  cerr << "expect lots of leetcode " << s.decodeString("7[leetcode]") << endl;
}

// the problem: we didn't consider > 1 digit