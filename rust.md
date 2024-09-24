
## RUST TILs
[go back](./README.md)

- String is for mutable
  - to truncate from start of string
    - create a new string
    - convert the old string into chars()
    - chain it into a skip(n) where n is the number of characters to truncate
    - finally collect()
- &str are slices and immutable
- unwrap unsafely converts from option to target type
- cannot access indexes of string slice using a[0] notation
  - instead &str.as_bytes().get(0).unwrap();
- use let asI:i32 = &str.parse().unwrap() for converting str to int
- for c in s.chars() to iterate chars of a String
- for i in 0..10 replaces traditional for loop
- for i in 0..=10 supported
- rust has the ruby-like implicit return of the last accessed variable
- rust vector equivalent is Vec and supports

```rs
Vec::push()
```

- HashMap is imported as such use

```rs
std::collections::HashMap;
```

- hashmaps converted to vectors using

```rs
let mut v: Vec<_> = freq.iter().collect();
```

- Vec has function sort_by

```rs
v.sort_by(|a,b| b.1.cmp(&a.1));
```

- the example above has a lambda function
- Hashmaps keys are retreived using .entry
- the return of .entry is a pointer which is the key that must be dereferenced to update the value at the key
- or_insert is used to give default values if key doesn't exist.

```rs
*freq.entry(value).or_insert(0) += 1;
```

- rust very type-picky:
- here, the addends' type must be specified (by sepcifying sum function generic)
- also note that the slicing needs usize type and wont accept i32

```rs
      dist2 = distance[0..start as usize].iter().sum::<i32>() + distance[destination as usize..sz].iter().sum::<i32>();
```

- Vec provides a way to get an iter() from it

  - with iter() you can do aggregate functions like .sum()

- nice syntax sugar to destructure a vector

```rs
    for path in paths.iter() {
      match path.as_slice() {
          [item0, item1] => {
              println!("Item 0: {}, Item 1: {}", item0, item1);
              // Do something with item0 and item1
          }
          _ => {
              // Handle the case where the nested vector doesn't have exactly two items
              println!("Invalid nested vector: {:?}", path);
          }
      }

```

- see 482 dest city for example of using hashmap (handling nonexistent keys, accessing k,v)

- cell and refcell usage, see 551

- sort a hashmap by key based (complex lambda) see 612
  - also convert hm to vec (typed as _ - leaves to compiler to figure out) use iter().collect()
  - also reminder accessing pairs from hm, items come as references and need to use * to dereference sometimes
  - finally, the pairs are accessed using p.0, p.1, and built in cmp method
```rs
    match x.cmp(&y) {
        Ordering::Less => println!("x is less than y"),
        Ordering::Equal => println!("x is equal to y"),
        Ordering::Greater => println!("x is greater than y"),
    }
```

- empty check is str.is_empty(), not str.empty()

- see 840 for
  - vec.windows(2) - chops the vec into subarrays size 2
  - e.g. [1,2,3,4] -> [1,2], [2,3], [3,4]

- see 855 for
  - comparing two Vec directly with == or !=
  - Iterator.zip(2nd iterator) - combines two iterators
  - iterator.skip(1) - returns an iterator without the first 1 elements

- see 856 for
  - iter.fold((0, 0), |(sum, count), &x| (sum + x, count + 1));
  - like js accum
  - note the first arg is arbitrary type def

- see 857 for
  - extend (appending arrays!)
  - partition (filtering array into two)

- see 871, directly convert strings into HashSet<char> with collect

- see 873, filter_map and enumerate
  - filtermap returns option (Some -> take it and map it, None -> filter it out )

- see 888 for how to clone a hashset

- see 890 for flat_map and u8 (byte) literal b'..'
  - convert Vec<Vec<i32>> to Vec<i32>

- see 932 for helper function
  - a function defined within another function.
  - scope limited, cannot access vars in outer function

- see 955 for convert chars to hashset using collect() with generic type cast
```rs
s.chars().collect::<HashSet<_>>().len() as i32
```

- 996 for enumerate
```rs
    for (index, &value) in vec.iter().enumerate() {
        if value == target1 {
            pos1 = Some(index);
        }
        if value == target2 {
            pos2 = Some(index);
        }
    }
```

- rust split
- called on str slice
```rs
  let words: Vec<&str> = text.split(' ').collect();
```

- see 985 for declare multiple muts

```rs
    let (mut l,mut r,mut u) = (0,0,0); // TIL: declare multiple on one line
```

- see  986 for as_bytes()
- String.as_bytes() converts char to u8

- 991 i32 to binary string
```rs
let binary_string = format!("{:b}", number);
```

- 997, insert at front of vec
```rs
v.insert(pos,item);
```

- 1055 - chunks
```rs
 for chunk in nums.chunks(2) {
   let c1 = chunk[0];
   let c2 = chunk[1];
```