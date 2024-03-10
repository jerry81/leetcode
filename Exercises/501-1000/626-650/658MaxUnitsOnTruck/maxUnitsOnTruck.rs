/*

1710. Maximum Units on a Truck
Easy
Topics
Companies
Hint
You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.



Example 1:

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
Example 2:

Input: boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
Output: 91


Constraints:

1 <= boxTypes.length <= 1000
1 <= numberOfBoxesi, numberOfUnitsPerBoxi <= 1000
1 <= truckSize <= 106
Seen this question in a real interview before?
1/4
Yes
No
Accepted
294.9K
Submissions
400.8K
Acceptance Rate
73.6%

*/

impl Solution {
  pub fn maximum_units(box_types: Vec<Vec<i32>>, truck_size: i32) -> i32 {
    // sort by box_type[1]
    // greedily take until truck_size 0
    let mut space_left = truck_size;
    let mut res = 0;
    let mut sorted = box_types.clone();
    sorted.sort_by(|a,b| { b[1].cmp(&a[1]) } );
    for v in sorted {
      if space_left = 0 {
        break
      }
      if v[0] >= space_left {
        res+=(v[1]*v[0]);
        space_left-=v[0];
      } else {
        res+=(v[1]*space_left);
      }
    }
    res
  }
}