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

#include <unordered_map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
  unordered_map<string,int> ticketTmpl;
  string hashTicket(string a, string b) { return a + "," + b; }
  unordered_map<string, set<string>> airports;
  int ticketCount = 0;

  vector<string> r(vector<string> accum, unordered_map<string,int> visited, int ticketsUsed,
                   string curAirport, int& target) {
    accum.push_back(curAirport);
    if (ticketsUsed == target) return accum;
    // greedy doesn't work for some cases
    for (string neigh : airports[curAirport]) {
      unordered_map<string,int> visitedC = visited;
      string asHash = hashTicket(curAirport, neigh);
      if (visitedC[asHash] > 0) {
        visitedC[asHash]--;
        vector<string> res = r(accum, visitedC, ticketsUsed + 1, neigh, target);
        if (!res.empty()) return res;
      }
    }
    return {};
  }

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    ticketCount = tickets.size();
    for (vector<string> s : tickets) {
      string src = s[0];
      string dest = s[1];
      string hsh = hashTicket(src,dest);
      ticketTmpl[hsh]++;

      airports[src].insert(dest);
    }
    vector<string> res = r({}, ticketTmpl, 0, "JFK", ticketCount);
    return res;
  }
};
/*

[["EZE","TIA"],["EZE","HBA"],["AXA","TIA"],["JFK","AXA"],["ANU","JFK"],["ADL","ANU"],["TIA","AUA"],["ANU","AUA"],["ADL","EZE"],["ADL","EZE"],["EZE","ADL"],["AXA","EZE"],["AUA","AXA"],["JFK","AXA"],["AXA","AUA"],["AUA","ADL"],["ANU","EZE"],["TIA","ADL"],["EZE","ANU"],["AUA","ANU"]]

*/