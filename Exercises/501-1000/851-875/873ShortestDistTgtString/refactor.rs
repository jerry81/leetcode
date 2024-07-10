impl Solution {
  pub fn closet_target(words: Vec<String>, target: String, start_index: i32) -> i32 {
      let tgtidxs: Vec<i32> = words.iter()
          .enumerate() // instead of for loop using indexes, this gets i,v pairs
          .filter_map(|(idx, word)| if *word == target { Some(idx as i32) } else { None }) // combines filter and map!
          .collect();

      if tgtidxs.is_empty() {
          return -1;
      }

      let sz = words.len() as i32;
      let mut res = i32::MAX;

      for &idx in &tgtidxs {
          if start_index == idx {
              return 0;
          }

          let direct_distance = (start_index - idx).abs(); // the comparison between these was unnecessary
          let wrap_around_distance = sz - direct_distance; // wow this makes sense
          res = res.min(direct_distance.min(wrap_around_distance));
      }

      res
  }
}