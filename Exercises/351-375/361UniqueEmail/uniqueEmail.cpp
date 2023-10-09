/*

929. Unique Email Addresses
Easy
2.6K
311
Companies
Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

For example, "m.y+name@email.com" will be forwarded to "my@email.com".
It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.



Example 1:

Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.
Example 2:

Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3


Constraints:

1 <= emails.length <= 100
1 <= emails[i].length <= 100
emails[i] consist of lowercase English letters, '+', '.' and '@'.
Each emails[i] contains exactly one '@' character.
All local and domain names are non-empty.
Local names do not start with a '+' character.
Domain names end with the ".com" suffix.
Accepted
448.4K
Submissions
669.1K
Acceptance Rate
67.0%

*/

#include <vector>

#include <string>

#include <unordered_set>

using namespace std;



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
    int numUniqueEmails(vector<string>& emails) {
      // split by @
      // drop text after +
      // drop .'s in local
      unordered_set<string> rs;

      for (string e: emails) {
        vector<string> spl = split(e,"@");
        string name = spl[0];
        string domain = spl[1];
        string newName = "";
        for (char c: name) {
          if (c == '+') break;

          if (c != '.') newName+=c;

        }
        newName += domain;
        rs.insert(newName);
      }
      return rs.size();
    }
};