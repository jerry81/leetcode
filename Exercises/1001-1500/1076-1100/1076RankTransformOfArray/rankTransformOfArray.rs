use std::collections::HashMap;

impl Solution {
  pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
    let mut sorted = arr.clone(); // must be mutable or borrow error
    let mut hm = HashMap::new();
    sorted.sort();
    let mut cur = i32::MIN;
    let mut rnk = 0;
    for i in sorted {
      if i != cur {
        rnk+=1;
      }
      cur = i;
      hm.insert(i, rnk);
    }
    let mut res: Vec<i32> = Vec::new();
    for i in arr {
      let item = hm.get(&i);
      res.push(*item.unwrap() as i32);
    }
    res
  }
}