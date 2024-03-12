/*

1704. Determine if String Halves Are Alike
Easy
Topics
Companies
Hint
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.

Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.



Example 1:

Input: s = "book"
Output: true
Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
Example 2:

Input: s = "textbook"
Output: false
Explanation: a = "text" and b = "book". a has 1 vowel whereas b has 2. Therefore, they are not alike.
Notice that the vowel o is counted twice.


Constraints:

2 <= s.length <= 1000
s.length is even.
s consists of uppercase and lowercase letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
213.4K
Submissions
275.2K
Acceptance Rate
77.5%

*/

impl Solution {
  pub fn halves_are_alike(s: String) -> bool {
    let list = ['a','e','i','o','u','A','E','I','O','U'];
    let sz = s.len();
    let mut vcount1 = 0;
    let mut vcount2 = 0;
    for i in 0..sz/2 {
      // num_string.chars().nth(i).unwrap()
      if list.contains(&s.chars().nth(i).unwrap()) { vcount1+=1;}
    }
    for i in sz/2..sz {
      if list.contains(&s.chars().nth(i).unwrap()) { vcount2+=1;}

    }
    vcount1 == vcount2
  }
}