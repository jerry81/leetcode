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
  fn get_next(mut s: Vec<char>) -> Option<Vec<char>> {
      let chars = ['a', 'b', 'c'];
      let n = s.len();

      for i in (0..n).rev() {
          let cur_index = chars.iter().position(|&c| c == s[i]).unwrap();

          for &next_char in chars.iter().skip(cur_index + 1) { // if c then it will do nothing for this i
              if i == 0 || s[i - 1] != next_char {
                  s[i] = next_char;

                  // Reset the rest with the smallest valid chars
                  for j in i + 1..n {
                      s[j] = *chars.iter().find(|&&c| c != s[j - 1]).unwrap(); // looks like the first statement in solution
                  }
                  /*
                  |&&c|: The double reference &&c is used because iter() yields references to
                  the elements of the array. The first & is the reference to the character,
                  and the second & dereferences it to get the actual character value.
                  This is a common pattern in Rust when working with iterators.
                  */

                  return Some(s);
              }
          }
      }

      None // No next happy string possible
  }

  pub fn get_happy_string(n: i32, k: i32) -> String {
      // Start with the smallest valid happy string: "aba..." pattern
      let mut s: Vec<char> = vec!['a'];
      for _ in 1..n {
          let next_char = ['a', 'b'].into_iter().find(|&c| c != *s.last().unwrap()/*last -> option*/).unwrap() /* find -> option */;
          s.push(next_char);
      }

      // Iteratively find the k-th happy string
      let mut count = 1;
      while count < k {
          if let Some(next) = Self::get_next(s.clone()) {
              s = next;
              count += 1;
          } else {
              return "".to_string(); // Not enough happy strings
          }
      }

      s.into_iter().collect()
  }
}
