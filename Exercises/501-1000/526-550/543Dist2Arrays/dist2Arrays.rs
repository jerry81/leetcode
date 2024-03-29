/*

1385. Find the Distance Value Between Two Arrays
Easy
Topics
Companies
Hint
Given two integer arrays arr1 and arr2, and the integer d, return the distance value between the two arrays.

The distance value is defined as the number of elements arr1[i] such that there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.



Example 1:

Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
Output: 2
Explanation:
For arr1[0]=4 we have:
|4-10|=6 > d=2
|4-9|=5 > d=2
|4-1|=3 > d=2
|4-8|=4 > d=2
For arr1[1]=5 we have:
|5-10|=5 > d=2
|5-9|=4 > d=2
|5-1|=4 > d=2
|5-8|=3 > d=2
For arr1[2]=8 we have:
|8-10|=2 <= d=2
|8-9|=1 <= d=2
|8-1|=7 > d=2
|8-8|=0 <= d=2
Example 2:

Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
Output: 2
Example 3:

Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
Output: 1


Constraints:

1 <= arr1.length, arr2.length <= 500
-1000 <= arr1[i], arr2[j] <= 1000
0 <= d <= 100
Seen this question in a real interview before?
1/4
Yes
No
Accepted
95.8K
Submissions
141.1K
Acceptance Rate
67.9%

*/

impl Solution {
  pub fn find_the_distance_value(arr1: Vec<i32>, arr2: Vec<i32>, d: i32) -> i32 {
    let mut sz = arr1.len();
    sz = sz.min(arr2.len());
    let mut a1:Vec<i32> = arr1.clone();
    let mut a2:Vec<i32> = arr2.clone();
    let mut res = 0;
    for i in a1 {
      let mut safe = true;
      for j in a2.clone() {
        /*
        In the second loop, you are iterating over a
        clone of arr2, which requires cloning.
        This is because a2.clone() creates a new owned
        Vec<i32> that is then iterated over.
        */
        if (i-j).abs() <= d {
            safe = false;
          break;
        }
      }
      if safe { res+=1; }
    }
    res
  }
}