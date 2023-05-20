/*


399. Evaluate Division
Medium
7.1K
633
Companies
You are given an array of variable pairs equations and an array of real numbers
values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai /
Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth
query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined,
return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will
not result in division by zero and that there is no contradiction.



Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]] Output:
[6.00000,0.50000,-1.00000,1.00000,-1.00000] Explanation: Given: a / b = 2.0, b /
c = 3.0 queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]] Output:
[3.75000,0.40000,5.00000,0.20000] Example 3:

Input: equations = [["a","b"]], values = [0.5], queries =
[["a","b"],["b","a"],["a","c"],["x","y"]] Output:
[0.50000,2.00000,-1.00000,-1.00000]


Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
Accepted
336.8K
Submissions
563.2K
Acceptance Rate
59.8%

*/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  unordered_map<string, unordered_map<string, vector<double>>> eqMap;
  void buildMap(vector<vector<string>>& equations, vector<double>& values) {
    // example a / b = 2
    // a = 2b
    // b = a / 2
    for (int i = 0; i < equations.size(); ++i) {
      vector<string> eq = equations[i];
      double val = values[i];
      string top = eq[0];
      string bottom = eq[1];
      vector<double> newT;
      newT.push_back(val);
      newT.push_back(1);
      eqMap[top][bottom] = newT;
      vector<double> newB;
      newB.push_back(1);
      newB.push_back(val);
      eqMap[bottom][top] = newB;
    }
  }

  void printMap() {
    for (auto a : eqMap) {
      for (auto b : a.second) {
        cout << a.first << ", " << b.first << " is " << b.second[0] << ", "
             << b.second[1] << endl;
      }
    }
  }

  double solve(vector<string> query) {
    double res;
    string op1 = query[0];
    string op2 = query[1];

    if (eqMap.find(op1) == eqMap.end()) {
      cout << "returning early 1 " << endl;
      return (double)-1;
    }

    if (eqMap.find(op2) == eqMap.end()) {
      cout << "returning early 2 " << endl;
      return (double)-1;
    }

    if (op1 == op2) return 1;

    if (eqMap[op1].find(op2) != eqMap[op1].end()) {
      cout << "ret early 3" << endl;
      return (double)eqMap[op1][op2][0] / (double)eqMap[op1][op2][1];
    }

    if (eqMap[op2].find(op1) != eqMap[op2].end()) {
      cout << "ret early 4" << endl;
      return (double)eqMap[op2][op1][1] / (double)eqMap[op1][op2][0];
    }

    // final case - substitution
    // look for a mutual key in the equation maps
    string intersect;
    for (auto a: eqMap[op1]) {
      for (auto b: eqMap[op2]) {
        if (a.first == b.first) {
          intersect = a.first;
          break;
        }
      }
    }

    double num = (double)eqMap[op1][intersect][0] * (double)eqMap[op2][intersect][1];
    double den = (double)eqMap[op2][intersect][0] * (double)eqMap[op1][intersect][1];
    res = num / den;

    return res;
  }

 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    vector<double> res;
    buildMap(equations, values);
    printMap();
    for (vector<string> q : queries) {
      res.push_back(solve(q));
    }
    return res;
  }
};

/*


// a/b = 2     a: { b: [2,1] }   b: { a: [1,2] }
// b/c = 3     c: { b: [1,3]  }  b: { c: [3,1] }
// a = 2b
// b = a/2
// b = 3c
// c = b/3
// a/c = ?    a has b, c has b .  substitute - [2,1] / [1,3] - 2 * 3
// (2b/b/3) -> 6
// b/a = (a/2/a) = .5


// a/b = 2
// b/c = 3
// a = 2b
// b = a/2
// b = 3c
// c = b/3
// a/c = ?
// (2b/b/3) -> 6  [2,1] / [1,3] -> 2 * 3 / 1*1
// b/a = (a/2/a) = .5

// a/b = 1.5
// b/c = 2.5
// bc/cd = 5
// a = 1.5b
// b = 1.5/a
// b = 2.5c
// c = b/2.5
// bc = 5cd
// cd = bc/5
// a/c = 1.5b/(b/2.5) 1.5*2.5 = 3.75 yes
// c/b = (b/2.5)/b = 1/2.5 = .4
// bc/cd = (5cd)/cd = 5
// cd/bc = 1/5 = .2

// a/b = .5
// .5
//

equations =
[["x1","x2"],["x2","x3"],["x3","x4"],["x4","x5"]]
values =
[3.0,4.0,5.0,6.0]
queries =
[["x1","x5"],["x5","x2"],["x2","x4"],["x2","x2"],["x2","x9"],["x9","x9"]]


chain of substitutions
first simplify
a,b, b,c c,d, d,e

a/b = 3
b/c = 4
c/d = 5
d/e = 6

a = 3b
b = a/3
b = 4c
c = b/4
c = 5d
d = c/5
d = 6e
e = d/6

next step of processing
combine and reduce

a: {b} b: {a,c} c: {b,d}, d: {c, e}
a-> e chain

c = b/4 = a/12
d = c/5 =  a/60
e = a/360
a/e = a / (a/360) = 360

wow!!
*/