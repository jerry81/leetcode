impl Solution {
  pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
    let mut adj_pairs: Vec<i32> = vec![];
    for i in 0..weights.len()-1 {
      adj_pairs.push(weights[i]+weights[i+1]);
    }
    adj_pairs.sort();
    let mut minsum = 0;
    let mut maxsum = 0;
    for i in 0..(k-1) {
        minsum+=adj_pairs[i as usize] as i64;
    }
    for i in 0..(k-1) {
        maxsum+=adj_pairs[adj_pairs.len()-(i as usize)-1] as i64;
    }
    maxsum-minsum
  }
}