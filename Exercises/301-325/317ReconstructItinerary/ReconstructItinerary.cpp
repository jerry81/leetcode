/*

332. Reconstruct Itinerary
Hard
5K
1.7K
Companies
You are given a list of airline tickets where tickets[i] = [fromi, toi]
represent the departure and the arrival airports of one flight. Reconstruct the
itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary
must begin with "JFK". If there are multiple valid itineraries, you should
return the itinerary that has the smallest lexical order when read as a single
string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than
["JFK", "LGB"]. You may assume all tickets form at least one valid itinerary.
You must use all the tickets once and only once.



Example 1:


Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
Example 2:


Input: tickets =
[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]] Output:
["JFK","ATL","JFK","SFO","ATL","SFO"] Explanation: Another possible
reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in
lexical order.


Constraints:

1 <= tickets.length <= 300
tickets[i].length == 2
fromi.length == 3
toi.length == 3
fromi and toi consist of uppercase English letters.
fromi != toi
Accepted
350.2K
Submissions
836.5K
Acceptance Rate
41.9%

*/

#include <map>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
  struct Airport {
    unordered_set<string> neighbors;
    unordered_set<string> parents;
  };
  map<string, Airport*> airports;

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    for (vector<string> s : tickets) {
      string src = s[0];
      string dest = s[1];
      if (airports.find(src) == airports.end()) {
        Airport* init = new Airport();
        airports[src] = init;
      }
      airports[src]->neighbors.insert(dest);
      airports[dest]->parents.insert(src);
    }
  }
};