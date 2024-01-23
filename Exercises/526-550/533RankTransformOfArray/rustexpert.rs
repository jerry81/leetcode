use std::collections::HashMap;

impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
    let mut sorted = arr.clone(); // yay that's me.
    sorted.sort_unstable(); // what!  don't guarantee relative order in case of equal compares.
    sorted.dedup(); // built in, remove duplicates.

    let rank_map: HashMap<i32, i32> = sorted // nice all in one
        .iter()
        .enumerate() // i think this is index/value destructure
        .map(|(index, &value)| {
            (value, index as i32 + 1) // this must be a hashmap entry, or pair
        })
        .collect();

    arr // use the original, this returns a copy
        .iter()
        .map(|&value| *rank_map.get(&value).unwrap()) // js map!
        .collect()
    }
}