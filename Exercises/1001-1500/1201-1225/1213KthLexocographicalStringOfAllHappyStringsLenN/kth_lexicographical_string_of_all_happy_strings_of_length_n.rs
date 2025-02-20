/*


1415. The k-th Lexicographical String of All Happy Strings of Length n
Medium
Topics
Companies
Hint
A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.



Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"


Constraints:

1 <= n <= 10
1 <= k <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
157.6K
Submissions
184.6K
Acceptance Rate
85.3%

*/
impl Solution {
  fn get_next(s:String, n:i32) -> String {
    if s.is_empty() { return s } // stop

    "".to_string()
  }
  fn get_first(n:i32) -> String {
    let mut res:Vec<char> = vec![];
    let mut a = true;
    let mut n = n;
    while n > 0 {
      if a {
        res.push('a');
      } else {
        res.push('b');
      }
      a = !a;
      n-=1;
    }
    res.into_iter().collect()
  }
  pub fn get_happy_string(n: i32, k: i32) -> String {
      Solution::get_first(n)
  }
}

/*
aba
abc
aca
acb
bab
bac
bca
bcb
cab
cba
cac
cbc
*/

/*

abab
abac
abca
abcb
acab
acac
acba
acbc

baba
babc
baca
bacb
bcab
bcba
bcac
bcbc

caba
cabc
caca
cacb
cbab
cbac
cbca
cbcb

24
*/

// n=3 12
// n=4 24