impl Solution {
  pub fn min_subsequence(nums: Vec<i32>) -> Vec<i32> {
    let mut cl = nums.clone();
    cl.sort();
    cl.reverse();
    let sm : i32 = cl.iter().sum();
    let mut csum = 0;
    let mut res: Vec<i32> = Vec::new();
    for i in cl {
        if csum > sm/2 {
            break;
        }
        res.push(i);
        csum+=i;
    }
    res
  }
}