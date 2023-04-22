/*
1312. Minimum Insertion Steps to Make a String Palindrome
Hard
3.4K
41
Companies
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.



Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
Accepted
87.8K
Submissions
130.3K
Acceptance Rate
67.3%

*/

#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {

    }
};

/*
01234556
leetcode
leetcoded
leetcodedo
leetcodedoc
leetcodedoct
leetcodedocte
leetcodedoctee
leetcodedocteel

leetcode
leetcodoe -> o's cancel (  leetcde )
leetcodoce -> c's cancel (leetde)
leetcodocte -> ts cancel leede
leetcodoctee -> led
leetcodocteel -> led

theory: any palindrome can be built by "balancing" two sides' freq maps
false:
"donedone"
- donedone - 5 inserts

- doneenod - 0 inserts

makeshift

makeshiftfihsekam

steely -> expect 4
steelyl
steelyle
steelylee
steelyleet
steelyleets

steely

stleely
styleely
styleelyt
styleelyts

- something to do with repeats

morgenstein

naive -> 10

ietsnegrom

but just 8 b/c of repeat e and repeat n?

instagram - expect 6

- naive
instagram argatsni - 8

i - 1
n - 1
s - 1
t - 1
a - 2
g - 1
r - 1
m - 1

- so n-1 -1 b/c of one repeat

i n s t a g r a m   0
i n s t a g r g a m   1
i n s t m a g r g a m  2
i n s t m a g r g a m t 3

distance of repeat made a difference

- multiple repeats

topics are string and DP

- make palindrome
- naive: - insert starting from last index and insert at end moving pointer backwards to 0


*/