/*

1370. Increasing Decreasing String
Easy
Topics
Companies
Hint
You are given a string s. Reorder the string using the following algorithm:

Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.



Example 1:

Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
Example 2:

Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
Seen this question in a real interview before?
1/4
Yes
No
Accepted
73.2K
Submissions
95.9K
Acceptance Rate
76.3%

*/
use std::collections::BTreeMap;

impl Solution {
    pub fn sort_string(s: String) -> String {
        let mut cv: Vec<char> = Vec::new();
        let mut sorted_map: BTreeMap<char, i32> = s.chars()
            .fold(BTreeMap::new(), |mut acc, c| {
                *acc.entry(c).or_insert(0) += 1;
                acc
            });


        let mut is_rev: bool = false;

        while !sorted_map.is_empty() {
            if is_rev {
                let keys: Vec<char> = sorted_map.keys().rev().cloned().collect();
                for key in keys {
                    if let Some(value) = sorted_map.get_mut(&key) {
                        cv.push(key);
                        *value -= 1;
                        if *value == 0 {
                            sorted_map.remove(&key);
                        }
                    }
                }
                is_rev = false;
            } else {
                let keys: Vec<char> = sorted_map.keys().cloned().collect();
                for key in keys {
                    if let Some(value) = sorted_map.get_mut(&key) {
                        cv.push(key);
                        *value -= 1;
                        if *value == 0 {
                            sorted_map.remove(&key);
                        }
                    }
                }
                is_rev = true;
            }
        }

        let res: String = cv.into_iter().collect();
        res
    }
}
