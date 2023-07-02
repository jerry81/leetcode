/*

2305. Fair Distribution of Cookies
Medium
1.1K
53
Companies
You are given an integer array cookies, where cookies[i] denotes the number of cookies in the ith bag. You are also given an integer k that denotes the number of children to distribute all the bags of cookies to. All the cookies in the same bag must go to the same child and cannot be split up.

The unfairness of a distribution is defined as the maximum total cookies obtained by a single child in the distribution.

Return the minimum unfairness of all distributions.



Example 1:

Input: cookies = [8,15,10,20,8], k = 2
Output: 31
Explanation: One optimal distribution is [8,15,8] and [10,20]
- The 1st child receives [8,15,8] which has a total of 8 + 15 + 8 = 31 cookies.
- The 2nd child receives [10,20] which has a total of 10 + 20 = 30 cookies.
The unfairness of the distribution is max(31,30) = 31.
It can be shown that there is no distribution with an unfairness less than 31.
Example 2:

Input: cookies = [6,1,3,2,2,4,1,2], k = 3
Output: 7
Explanation: One optimal distribution is [6,1], [3,2,2], and [4,1,2]
- The 1st child receives [6,1] which has a total of 6 + 1 = 7 cookies.
- The 2nd child receives [3,2,2] which has a total of 3 + 2 + 2 = 7 cookies.
- The 3rd child receives [4,1,2] which has a total of 4 + 1 + 2 = 7 cookies.
The unfairness of the distribution is max(7,7,7) = 7.
It can be shown that there is no distribution with an unfairness less than 7.


Constraints:

2 <= cookies.length <= 8
1 <= cookies[i] <= 105
2 <= k <= cookies.length
Accepted
32.3K
Submissions
50.1K
Acceptance Rate
64.5%

*/

#include <vector>

using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {

    }
};

/*

analysis

another way to look at this -

minimize the deviation between the k groups

cookies = [8,15,10,20,8], k = 2
// gen all possiblities

8
8, 15
8, 10
8, 20
8, 8
8 15 10
8 15 20
8 15 8
8 15 10 20
8 15 10 8

[6,1,3,2,2,4,1,2], k = 3
[6], [1,3,2,2,4,1,2] k = 2
  [6] [1] k=1
[1], [6,3,2,2,4,1,2] k = 2
...
[2], [6,1,3,2,2,4,1], k = 2
[6,1], [3,2,2,4,1,2], k = 2
[6,3], [1,2,2,4,1,2], k = 2
[6,2], [1,3,2,4,1,2], k = 2
...
[6,2], [1,3,2,2,4,1], k = 2
- feel a complexity explosion with this method
*/