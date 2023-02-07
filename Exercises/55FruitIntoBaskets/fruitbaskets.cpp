/*

Fruit Into Baskets
Medium
2.4K
173
Companies
You are visiting a farm that has a single row of fruit trees arranged from left
to right. The trees are represented by an integer array fruits where fruits[i]
is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some
strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit.
There is no limit on the amount of fruit each basket can hold. Starting from any
tree of your choice, you must pick exactly one fruit from every tree (including
the start tree) while moving to the right. The picked fruits must fit in one of
your baskets. Once you reach a tree with fruit that cannot fit in your baskets,
you must stop. Given the integer array fruits, return the maximum number of
fruits you can pick.



Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].


Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length

*/

#include <iostream>
#include <vector>

using namespace std;

// find longest consecutive

class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int idx = 0;
    int end = 1;
    int bucket1 = -1;
    int bucket2 = -1;
    int max = 0;
    int latestBucket1 = 0;
    int latestBucket2 = 0;
    bucket1 = fruits[idx];
    while (fruits[end] == bucket1) {
      latestBucket1 = end;
      end++;
    }
    bucket2 = fruits[end];
    latestBucket2 = end;

    while (end < fruits.size()) {
      if (fruits[end] == bucket1) {
        latestBucket1 = end;
      } else if (fruits[end] == bucket2) {
        latestBucket2 = end;
      } else {
        int len = end - idx;
        if (len > max) max = len;

        bool oneLTtwo = latestBucket1 < latestBucket2;
        idx = oneLTtwo ? (latestBucket1 + 1) : (latestBucket2 + 1);
        if (oneLTtwo) {
          bucket1 = fruits[end];
          latestBucket1 = end;
        } else {
          bucket2 = fruits[end];
          latestBucket2 = end;
        }
      }
      ++end;
    }

    // one last cleanup
    int len = end - idx;
    if (len > max) max = len;
    return max;
  }
};

int main() {
  Solution s;
  vector<int> test = {0,2,3,2,2};
  cerr << s.totalFruit(test) << endl;
  return 0;
};