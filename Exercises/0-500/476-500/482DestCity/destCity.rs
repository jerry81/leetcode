/*
1436. Destination City
Easy
1.6K
84
Companies
You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.



Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo"
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".
Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are:
"D" -> "B" -> "C" -> "A".
"B" -> "C" -> "A".
"C" -> "A".
"A".
Clearly the destination city is "A".
Example 3:

Input: paths = [["A","Z"]]
Output: "Z"


Constraints:

1 <= paths.length <= 100
paths[i].length == 2
1 <= cityAi.length, cityBi.length <= 10
cityAi != cityBi
All strings consist of lowercase and uppercase English letters and the space character.
Accepted
161.5K
Submissions
206.6K
Acceptance Rate
78.2%
*/
use std::collections::HashMap;

impl Solution {
  pub fn dest_city(paths: Vec<Vec<String>>) -> String {
    let mut hm:HashMap<String,i32> = HashMap::new();

    for path in paths.iter() {
      match path.as_slice() {
          [item0, item1] => {
            *hm.entry(item0.to_string()).or_insert(0) += 1;
            *hm.entry(item1.to_string()).or_insert(0);
            // Do something with item0 and item1


          }
          _ => {
              // Handle the case where the nested vector doesn't have exactly two items
              println!("Invalid nested vector: {:?}", path);
          }
      }
    }
    for (key, value) in hm.iter() {
      if *value == 0 {
        return key.to_string()
      }
    }
    "".to_string()
  }
}