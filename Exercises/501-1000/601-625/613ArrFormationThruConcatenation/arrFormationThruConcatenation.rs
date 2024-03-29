/*


1640. Check Array Formation Through Concatenation
Easy
Topics
Companies
Hint
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].

Return true if it is possible to form the array arr from pieces. Otherwise, return false.



Example 1:

Input: arr = [15,88], pieces = [[88],[15]]
Output: true
Explanation: Concatenate [15] then [88]
Example 2:

Input: arr = [49,18,16], pieces = [[16,18,49]]
Output: false
Explanation: Even though the numbers match, we cannot reorder pieces[0].
Example 3:

Input: arr = [91,4,64,78], pieces = [[78],[4,64],[91]]
Output: true
Explanation: Concatenate [91] then [4,64] then [78]


Constraints:

1 <= pieces.length <= arr.length <= 100
sum(pieces[i].length) == arr.length
1 <= pieces[i].length <= arr.length
1 <= arr[i], pieces[i][j] <= 100
The integers in arr are distinct.
The integers in pieces are distinct (i.e., If we flatten pieces in a 1D array, all the integers in this array are distinct).
Seen this question in a real interview before?
1/4
Yes
No
Accepted
80.3K
Submissions
142.4K
Acceptance Rate
56.4%

*/

impl Solution {
  pub fn can_form_array(arr: Vec<i32>, pieces: Vec<Vec<i32>>) -> bool {
    let sz = arr.len();
    for v in pieces {
      let first = v[0];
      let vsz = v.len();
      let mut found = false;
      for i in 0..sz {
        if first == arr[i] {
          found = true;
          for j in 1..vsz {
            if i+j >= sz { return false; }
            if arr[i+j] != v[j] {
              return false;
            }
          }
        }
      }
      if !found { return false; }
    }
    true
  }
}