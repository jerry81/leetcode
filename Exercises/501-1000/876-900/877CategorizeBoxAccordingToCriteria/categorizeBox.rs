/*

2525. Categorize Box According to Criteria
Easy
Topics
Companies
Hint
Given four integers length, width, height, and mass, representing the dimensions and mass of a box, respectively, return a string representing the category of the box.

The box is "Bulky" if:
Any of the dimensions of the box is greater or equal to 104.
Or, the volume of the box is greater or equal to 109.
If the mass of the box is greater or equal to 100, it is "Heavy".
If the box is both "Bulky" and "Heavy", then its category is "Both".
If the box is neither "Bulky" nor "Heavy", then its category is "Neither".
If the box is "Bulky" but not "Heavy", then its category is "Bulky".
If the box is "Heavy" but not "Bulky", then its category is "Heavy".
Note that the volume of the box is the product of its length, width and height.



Example 1:

Input: length = 1000, width = 35, height = 700, mass = 300
Output: "Heavy"
Explanation:
None of the dimensions of the box is greater or equal to 104.
Its volume = 24500000 <= 109. So it cannot be categorized as "Bulky".
However mass >= 100, so the box is "Heavy".
Since the box is not "Bulky" but "Heavy", we return "Heavy".
Example 2:

Input: length = 200, width = 50, height = 800, mass = 50
Output: "Neither"
Explanation:
None of the dimensions of the box is greater or equal to 104.
Its volume = 8 * 106 <= 109. So it cannot be categorized as "Bulky".
Its mass is also less than 100, so it cannot be categorized as "Heavy" either.
Since its neither of the two above categories, we return "Neither".


Constraints:

1 <= length, width, height <= 105
1 <= mass <= 103
Seen this question in a real interview before?
1/5
Yes
No
Accepted
33.1K
Submissions
92.7K
Acceptance Rate
35.7%

*/

impl Solution {
  pub fn categorize_box(length: i32, width: i32, height: i32, mass: i32) -> String {
    let is_bulky_dim = length >= 10_000 || width >= 10_000 || height >= 10000;
    let is_bulky_vol = (length * width) as i64 * height as i64 >= 1_000_000_000;
    let is_bulky = is_bulky_dim || is_bulky_vol;
    let is_heavy = mass >= 100;
    if is_heavy && is_bulky { return "Both".to_string() }

    if !is_heavy && !is_bulky { return "Neither".to_string() }

    if is_bulky && !is_heavy { return "Bulky".to_string() }

    "Heavy".to_string()
  }
}