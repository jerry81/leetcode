/*

1220. Count Vowels Permutation
Hard
2.7K
182
Companies
Given an integer n, your task is to count how many strings of length n can be
formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.



Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu",
"oi", "ou" and "ua". Example 3:

Input: n = 5
Output: 68


Constraints:

1 <= n <= 2 * 10^4
Accepted
115.1K
Submissions
190.7K
Acceptance Rate
60.4%

*/
#include <cmath>
using namespace std;

class Solution {
 public:
  int countVowelPermutation(int n) {
    const int MOD = pow(10,9) + 7;
    long long int a = 1;
    long long int e = 1;
    long long int ii = 1;
    long long int o = 1;
    long long int u = 1;
    for (int i = 0; i < n; ++i) {
      long long int nextA = e+ii+u;
      long long int nextE = a+ii;
      long long int nextII = e+o;
      long long int nextO = ii;
      long long int nextU = ii+o;
      a = nextA % MOD;
      e = nextE % MOD;
      ii = nextII % MOD;
      o = nextO % MOD;
      u = nextU % MOD;
    }
    return (a+e+ii+o+u) % MOD;
  }
};