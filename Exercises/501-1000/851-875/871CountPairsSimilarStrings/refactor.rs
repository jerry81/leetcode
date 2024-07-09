use std::collections::HashSet;

impl Solution {
    pub fn similar_pairs(words: Vec<String>) -> i32 {
        // Transform words into Vec<HashSet<char>> directly
        let vhs: Vec<HashSet<char>> = words // kill the forloop!
            .iter()
            .map(|w| w.chars().collect::<HashSet<char>>()) // collect with a type
            .collect();

        let mut res = 0;
        let sz = vhs.len();

        for i in 0..sz - 1 {
            for j in i + 1..sz {
                if vhs[i] == vhs[j] {
                    res += 1;
                }
            }
        }

        res
    }
}