#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  unordered_map<string, unordered_map<string, double>> eqMap;

  void buildMap(vector<vector<string>>& equations, vector<double>& values) {
    for (int i = 0; i < equations.size(); ++i) {
      vector<string>& eq = equations[i];
      double val = values[i];
      string top = eq[0];
      string bottom = eq[1];
      eqMap[top][bottom] = val;
      eqMap[bottom][top] = 1 / val;
    }
  }

  double solveBFS(vector<string>& query) {
    string op1 = query[0];
    string op2 = query[1];
    if (eqMap.find(op1) == eqMap.end() || eqMap.find(op2) == eqMap.end()) {
      return -1.0;
    }

    if (op1 == op2) {
      return 1.0;
    }

    unordered_map<string, bool> visited;
    queue<pair<string, double>> nn;
    nn.push({op1, 1.0});
    visited[op1] = true;

    while (!nn.empty()) {
      pair<string, double> cur = nn.front();
      nn.pop();
      unordered_map<string, double>& neighbors = eqMap[cur.first];
      for (auto pr : neighbors) {
        if (visited[pr.first]) {
          continue;
        }

        double newval = cur.second * pr.second;
        if (pr.first == op2) {
          return newval;
        }

        nn.push({pr.first, newval});
        visited[pr.first] = true;
      }
    }

    return -1.0;
  }

 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    vector<double> res;
    buildMap(equations, values);
    for (vector<string>& q : queries) {
      res.push_back(solveBFS(q));
    }
    return res;
  }
};