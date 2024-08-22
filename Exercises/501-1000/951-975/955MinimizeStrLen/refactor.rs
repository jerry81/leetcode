use std::collections::HashSet;

impl Solution {
    pub fn minimized_string_length(s: String) -> i32 {
        s.chars().collect::<HashSet<_>>().len() as i32 // TIL: collect is the typed method
    }
}