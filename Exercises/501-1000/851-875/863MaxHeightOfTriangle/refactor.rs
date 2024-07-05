impl Solution {
  pub fn max_height_of_triangle(red: i32, blue: i32) -> i32 {
      fn calculate_height(mut red: i32, mut blue: i32, start_with_red: bool) -> i32 {
          let mut height = 0;
          let mut layer_size = 1;
          let mut use_red = start_with_red;

          loop {
              if use_red {
                  if red < layer_size {
                      break;
                  } else {
                      height += 1;
                      red -= layer_size;
                  }
              } else {
                  if blue < layer_size {
                      break;
                  } else {
                      height += 1;
                      blue -= layer_size;
                  }
              }
              layer_size += 1;
              use_red = !use_red;
          }

          height
      }

      let height_start_with_red = calculate_height(red, blue, true);
      let height_start_with_blue = calculate_height(red, blue, false);

      height_start_with_red.max(height_start_with_blue)
  }
}