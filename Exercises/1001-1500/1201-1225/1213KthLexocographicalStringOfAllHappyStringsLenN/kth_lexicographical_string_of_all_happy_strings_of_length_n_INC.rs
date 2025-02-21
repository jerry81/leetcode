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
    println!("string is {}", s);
    if s.is_empty() { return s } // stop

    let mut res:Vec<char> = s.clone().chars().collect();
    for idx in (0..n).rev() {
      let lc = s.chars().nth(idx as usize).unwrap();

      if idx > 0 {
        let prev = s.chars().nth((idx-1) as usize).unwrap();
         let cur = s.chars().nth((idx) as usize).unwrap();
         println!("prev is {}", prev);

        if (prev == 'a' && cur == 'b') || (prev == 'b' && cur == 'a') {
          // replace idx with nxt
          res[idx as usize] = 'c';
          // reset
          let rest = Solution::get_first(n-idx, prev!='a');

          println!("rest is {}", rest);
          break;
        } else if (prev == 'a' && cur == 'c') || (prev == 'c' && cur == 'a') {
            let rest = Solution::get_first(n-idx, prev!='a');
            println!("rest is {}", rest);
            break;
        }
      }
      println!("working with {}", lc);
    }

    res.into_iter().collect::<String>()
  }
  fn get_first(n:i32,start_a:bool) -> String {
    let mut res:Vec<char> = vec![];
    let mut a = start_a;
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
      let mut cur:String = Solution::get_first(n, true);
      for i in 0..k {
        cur = Solution::get_next(cur, n);
        println!("cur is {}", cur);
      }
      cur
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