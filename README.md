# leetcode

leetcode solutions

# Algorithms

## euclidean algorithm for gcd

- gcd(a,b)is equal to gcd(b, a%b)
until a%b becomes zero.  in case of a%b, b is the gcd.

## Djikstra's

1.  Setup priority Queue table that will store weighted edges
2.  Setup distances table, initialize all nodes's distances as inf
3.  arbitrarily pick start node - mark dist as 0, insert into pq
4.  while pq not empty
5.  Pop edge, update distance, mark as visited
6.  for each neighboring edge, if not visited add to queue

## Find median in two arrays

- we know the target "index" (half of all elements ish)
  - so we need to find the number that gives us that target index
  - start with nums1 midpoint (idxSum is idx of nums1's midpoint)
  - search in nums2 for this value (totalIdx is idxSum + idxFound)
  - we then repeat with our new search space depending totalIdx's value

## Find if string a is subsequence of string b

- use recursion
- base case is a empty -> return true
- search for first char in a in b
- if not found -> false
- pop a
- drop all chars before first found index in b
- r(a, b)

## champagne pouring

- simulation - this is basically a brute force application of math

## greedy O(N) solve subsequence dropping duplicates

- don't know why this problem kicked my ass so much.
- given a string, remove dups and give the lexocographically smallest subsequence

- plow ahead from 0 to N, one pass, no recursion
- stack keeps track of items in your subsequence
- always compare top of stack with the current item
- if item is lexocographically larger, add to stack
- if smaller pop with condition that you will be able to use a duplicate later on
  - (genius) - check if there is a possible duplicate later on by keeping track of the last index the item appears.

## if you want to build a tree and return the whole tree (aka first node)

- you need two pointers - one to the head of the new tree
- another for the tail.

## Khan's Topological Sort

- application - 380 - parallel courses 3
- only for directed Acyclic graph
- calculate indegrees for all nodes
- use queue - store current indegree==0
- iterate through lowest indegrees (0)
  - while updating indegrees for their neighbors
  - push to queue if indegree 0

# TIL

```

User
can you describe the syntax here (c++)

bool operator()(int a, int b) { return a < b; }

ChatGPT
Certainly! The code snippet you provided is an example of a function call operator overload in C++.

In C++, the operator() is a special function name that allows an object to be called as if it were a function. This feature is often used in functors or function objects, which are objects that can be treated and used as functions.

In this case, the function call operator operator() is defined within a class or struct that is not explicitly mentioned in the provided code snippet. It takes two integer parameters, a and b, and returns a boolean value (bool).

The implementation of the function simply compares the values of a and b using the less-than operator (<). It returns true if a is less than b, and false otherwise. The function acts as a binary predicate that compares two integers for a specific ordering criteria.

This function call operator can be used when an instance of the class or struct is invoked as if it were a function, such as in the following example:

SomeClass compare;
bool result = compare(10, 20);
In the above example, an instance of the class or struct containing the operator() function is created as compare. Then, the instance is called as a function with the arguments 10 and 20. The operator() function is executed, and the result is stored in the variable result.

```

## create a single int from a vector of ints (can be applied to binary etc also)
```cpp
for (int digit:digits) {
  result = result*10 + digit;
}
```

## math: sum of series of consecutive numbers between a and b

- S = n/2 \* (a+b) where n is number of terms, a is first and b is last term.
- e.g. from 2 to 8
- 8 - 2 + 1 terms so n is 7
- 7 / 2 \* (2 + 8) = 70 / 2 = 35.

- from 3 to 9
- 21 + 63 = 84 / = 42

## noob c++ mistakes

- using namespace std; -imposing on others
  - alternative

```cpp
using std::cout, std::string, std::endl;
```

- std::endl bad perf
  - alternative

```cpp
  cout << "yay " << "\n";
```

- for loop over ranged base
  - alternative

```cpp
  for (const auto &a: arr) {
  }
```

- for loop when you could use find_if

```cpp
  const auto is_positive = [](const auto &x){ return x > 0; };
  auto it = find_if(a.cbegin(), b.cbegin(), is_positive);
```

- using c-style array over std:array

- using reinterpret_cast?!

  - std::bit_cast does the same thing

- using const_cast?!

- not knowing looking up a nonexistent key with [] in map inserts it.

- not marking const when you should

- not using structured bindings

```cpp
for (const auto&[name,hex] : amap) {
}
```

- can be done with struct too
- variables assigned in order they appear in the struct.

- using multiple out params (&params)
- use struct instead

- constexpr to let compiler know to compute at compile time.

- destructors (what) should be marked virtual (what)

```cpp
class A {
public:
  virtual ~A() {
  }
}
```

- fields initialized in order they are declared, not the order they appear in initializer list

- know default vs value initialization
  - default initialized

```cpp
  int x;
  int *x2 = new int
```

- these contain garbage
- value initialized

```cpp
  int y{};
  int *y2 = new int{};
```

- init to 0;

- no magic numbers
- instead use constexpr

- do not modify container while looping over it.

- return moved? local variable
  - moved means ownership transfers to one location to another
  - aka mutated
  - there is also std::move in c++
    - a perf optimization - "move semantics"
  - impl is a static_cast, double &&??

```cpp
constexpr int&& // && is rvalue reference to an int?
move(int &&value) no except {
  return static_cast<int &&>(value);
}
```

- eval order not always l to r

- unnecessary heap allocations

  - heap allocation slower than stack allocation
  - using "new" uses heap
  - declaring without makes it stack allocated.

- not using shared pointer and unique ptrs to do heap allocations

  - unique ptr - gives heap-allocated pointer and when it goes out of scope, it deletes it
  - shared ptr more expensive

- mistake: constructing unique or shared directly instead of using make_unique or make_shared
- not this:

```cpp
  auto customer = std::shared_ptr<Record>(new Record{0, "James"});
```

- but this:

```cpp
  auto customer = std::make_shared<Record>(0, "James");
```

- using new or delete when you can use unique_ptr

- any manually resource mgmt

- overuse of smart pointer when raw ptr can be used (don't care about ownership)

- overuse of shared_ptr (not sure of usage)

- shared_ptr is not thread safe

- confusing _const and const _

- const applies to whatever is to its left, unless it is on the left.

- do not ignore compiler warnings!


## SQL tips

- left join if you want to display all items from left table regardless if they have a corresponding item in right table (nulls where there are holes)
- if you want to self join use inner join same table use alias to distinguish
- full join puts all the rows togethers - there will be nulls where there is no foreign key match
- select distinct to remove dup rows
- the "on" in join on is just to determine which columns to join on.
- delete usage:

```sql
delete from table1 using table2 where do your stuff here returning *;
```

- delete usage when same table:

```sql
delete from table1 a using table2 b where a.id = b.id and etc... returning *;
```

- LAG syntax
- comparing dates with INTERVAL '1 day'

```sql
select id from (
  select id, temperature, recordDate,
  LAG(recordDate) OVER (ORDER BY recordDate) AS prev_recordDate,
  LAG(temperature) OVER (ORDER BY recordDate) AS prev_temp
  from Weather
)
where prev_temp < temperature and recordDate = prev_recordDate + INTERVAL '1 day';
```

- select distinct on (column u want distinct)
- also orderby multiple

```sql
select distinct on (player_id) player_id, event_date as first_login from Activity order by player_id, event_date;

```


- see 513 for notes on numeric
col_name::numeric to fix float division
round(num,2) to format decimals to 2 digits
avg(case when {condition} then a else b end )
conditional aggregate
count(*) to get the # items in the group

- see 517 for usage on full join and coalesce for default values
- also join on date between two dates

- see 521 for usage on cross join and left join magic
- cross join
  - no "on" clause
  - combines all possible combinations of each row of a and b

- see 532 for usage on having clause together with where clause

- see 564 for count, distinct, nullif

- see 567 for using regex
- see 572 for regex /y
- see 611 for WITH
  - and multiple orderby
- 620 for postgres || (concatenation)
  - concatenate two columns for use in a groupby
  - round in postgres takes numeric, not double
  - cast with variable::type
- 621 for UPPER, LOWER, SUBSTRING usage
- 648 for UNION, constant string, "merging" columns into a single column
- see 690 for LIKE (reg expD), CASE WHEN ELSE END

- see 696 for timestamp extract year
  - also joining a subquery

- see 715 for review on "IN" keyword

- see 1222 for dense rank and rank

- see 1226 for WHERE (tuple) IN and MAX trick

[Rust TILs](./rust.md)

## todo

- come back to [method 4: cantor's diagonal argument](https://leetcode.com/problems/find-unique-binary-string/editorial/?envType=daily-question&envId=2023-11-16)

- refactor 476DayOfWeek
````

- study 810