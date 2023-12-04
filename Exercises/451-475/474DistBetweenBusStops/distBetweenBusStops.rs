/*

1184. Distance Between Bus Stops
Easy
724
81
Companies
A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e. clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.



Example 1:



Input: distance = [1,2,3,4], start = 0, destination = 1
Output: 1
Explanation: Distance between 0 and 1 is 1 or 9, minimum is 1.


Example 2:



Input: distance = [1,2,3,4], start = 0, destination = 2
Output: 3
Explanation: Distance between 0 and 2 is 3 or 7, minimum is 3.


Example 3:



Input: distance = [1,2,3,4], start = 0, destination = 3
Output: 4
Explanation: Distance between 0 and 3 is 6 or 4, minimum is 4.


Constraints:

1 <= n <= 10^4
distance.length == n
0 <= start, destination < n
0 <= distance[i] <= 10^4
Accepted
55.5K
Submissions
103K
Acceptance Rate
53.9%

*/

impl Solution {
  pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
    let sz = distance.len();
    let mut dist1 = 0;
    let mut dist2 = 0;
    let mut res = 0;
    if start == destination { return 0; }

    if start < destination {
      dist1 = distance[start as usize..destination as usize].iter().sum();
      dist2 = distance[0..start as usize].iter().sum::<i32>() + distance[destination as usize..sz].iter().sum::<i32>();
    } else {
      dist1 = distance[start as usize..sz].iter().sum::<i32>()+distance[0..destination as usize].iter().sum::<i32>();
      dist2 = distance[destination as usize..start as usize].iter().sum();
    }
    res = dist1.min(dist2);
    res
  }
}