/*

1203. Sort Items by Groups Respecting Dependencies
Hard
852
125
Companies
There are n items each belonging to zero or one of m groups where group[i] is
the group that the i-th item belongs to and it's equal to -1 if the i-th item
belongs to no group. The items and the groups are zero indexed. A group can have
no item belonging to it.

Return a sorted list of the items such that:

The items that belong to the same group are next to each other in the sorted
list. There are some relations between these items where beforeItems[i] is a
list containing all the items that should come before the i-th item in the
sorted array (to the left of the i-th item). Return any solution if there is
more than one solution and return an empty list if there is no solution.



Example 1:



Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
[[],[6],[5],[6],[3,6],[],[],[]] Output: [6,3,4,1,5,2,0,7] Example 2:

Input: n = 8, m = 2, group = [-1,-1,1,0,0,1,0,-1], beforeItems =
[[],[6],[5],[6],[3],[],[4],[]] Output: [] Explanation: This is the same as
example 1 except that 4 needs to be before 6 in the sorted list.


Constraints:

1 <= m <= n <= 3 * 104
group.length == beforeItems.length == n
-1 <= group[i] <= m - 1
0 <= beforeItems[i].length <= n - 1
0 <= beforeItems[i][j] <= n - 1
i != beforeItems[i][j]
beforeItems[i] does not contain duplicates elements.
Accepted
17K
Submissions
32.6K
Acceptance Rate
52.2%

*/

#include <map>
#include <unordered_set>
#include <vector>

using namespace std;

struct InDegree {
  int id = -1;
  int val = 0;
  InDegree(int i, int v) : id(i), val(v){};
};

bool sortIndegrees(InDegree* a, InDegree* b) { return a->val < b->val; }
class Solution {
  map<int, unordered_set<int>> neighbors;
  map<int, unordered_set<int>> group_neighbors;

  vector<InDegree*> indegrees;
  vector<InDegree*> groupIndegrees;

 public:
  vector<int> sortItems(int n, int m, vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    vector<int> result;
    int groupId = m;
    for (int i = 0; i < group.size(); ++i) {
      InDegree* cur = new InDegree(i, 0);
      indegrees.push_back(cur);
      if (group[i] == -1) {
        group[i] = groupId;
        groupId++;
      }
    }

    for (int i = 0; i < groupId; ++i) {
      InDegree* cur = new InDegree(i, 0);
      groupIndegrees.push_back(cur);
    }

    for (int child = 0; child < n; ++child) {
      vector<int> parents = beforeItems[child];
      int childGroupId = group[child];
      for (int parent : parents) {
        neighbors[parent].insert(child);
        int parentGroupId = group[parent];
        if (childGroupId != parentGroupId) {
          // group dependency detected
          // add group dependency
          if (group_neighbors[parentGroupId].find(childGroupId) !=
              group_neighbors[parentGroupId].end()) {
            group_neighbors[parentGroupId].insert(childGroupId);
            groupIndegrees[childGroupId]->val++;
          }
          // add group neighbor
        }
      }
      indegrees[child]->val += parents.size();
    }
    vector<InDegree*> copied = indegrees;
    sort(indegrees.begin(), indegrees.end());
    vector<int> sortedIds;
    while (!indegrees.empty()) {
      if (indegrees[0]->val > 0) return {};
      vector<InDegree*> nextIndegrees;
      for (int i = 0; i < indegrees.size(); ++i) {
        InDegree* cur = indegrees[i];
        if (cur->val == 0) {
          sortedIds.push_back(cur->id);
          unordered_set<int> toReduce = neighbors[cur->id];
          for (int i : toReduce) {
            copied[i]->val--;
          }
        } else {
          nextIndegrees.push_back(cur);
        }
      }
      sort(nextIndegrees.begin(), nextIndegrees.end(), sortIndegrees);
      indegrees = nextIndegrees;
    }
    vector<int> sortedGroupIds;
    vector<InDegree*> origGroups = groupIndegrees;
    sort(groupIndegrees.begin(), groupIndegrees.end(),sortIndegrees);
    while (!groupIndegrees.empty()) {
      if (groupIndegrees[0]->val > 0) return {};
      vector<InDegree*> nextIndegrees;
      for (int i = 0; i < groupIndegrees.size(); ++i) {
        InDegree* cur = groupIndegrees[i];
        if (cur->val == 0) {
          sortedGroupIds.push_back(cur->id);
          unordered_set<int> toReduce = group_neighbors[cur->id];
          for (int i : toReduce) {
            origGroups[i]->val--;
          }
        } else {
          nextIndegrees.push_back(cur);
        }
      }
      sort(nextIndegrees.begin(), nextIndegrees.end(), sortIndegrees);
      groupIndegrees = nextIndegrees;
    }

    // final stretch: populate the final list in order based on group order

    vector<vector<int>> reorderedGroups(groupId);
    for (int i:sortedIds) {
      reorderedGroups[group[i]].push_back(i);
    }

    for (int gr: sortedGroupIds) {
      result.insert(result.end(), reorderedGroups[gr].begin(), reorderedGroups[gr].end());
    }
    // for (InDegree i: indegrees) {
    //   cout << "indegree " << i.id << ", " << i.val << endl;
    // }

    // for (InDegree i: groupIndegrees) {
    //   cout << "group indegree " << i.id << ", " << i.val << endl;
    // }
    // make beforeitems into a graph?
    return result;
  }
};

/*

[-1,-1,1,0,0,1,0,-1], beforeItems = [[],[6],[5],[6],[3],[],[4],[]]
contradiction:

6 before 1
5 before 2
6 before 3
3 before 4
4 before 6

6->3->4->6 (circular)

*/