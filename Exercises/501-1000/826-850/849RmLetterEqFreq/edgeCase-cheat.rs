use std::collections::HashMap;

impl Solution {
    pub fn equal_frequency(word: String) -> bool {
        let mut freq: HashMap<char, i32> = HashMap::new();
        let mut fof: HashMap<i32, i32> = HashMap::new();

        // Count frequency of each character
        for c in word.chars() {
            *freq.entry(c).or_insert(0) += 1;
        }

        // Count frequency of frequencies
        for (_, f) in &freq {
            *fof.entry(*f).or_insert(0) += 1;
        }

        // Edge case 1: all characters have frequency 1
        if fof.len() == 1 && fof.contains_key(&1) {
            return true;
        }

        // Edge case 2: there is only one unique frequency and its count is 1
        if fof.len() == 1 && *fof.iter().next().unwrap().1 == 1 {
            return true;
        }

        // If there are more than 2 different frequencies, it's not possible
        if fof.len() != 2 {
            return false;
        }

        let mut sorted: Vec<(&i32, &i32)> = fof.iter().collect();
        sorted.sort_by(|a, b| a.0.cmp(b.0));

        let (lesserFreqKey, lesserFreqCount) = sorted[0];
        let (greaterFreqKey, greaterFreqCount) = sorted[1];

        // Check if we can make all frequencies equal by removing one character
        if (*lesserFreqKey == 1 && *lesserFreqCount == 1) || (*greaterFreqKey == 1 && *greaterFreqCount == 1) {
            return true;
        }

        // Check if reducing one of the more frequent characters' count makes all counts equal
        if *greaterFreqKey - *lesserFreqKey == 1 && *greaterFreqCount == 1 {
            return true;
        }

        false
    }
}