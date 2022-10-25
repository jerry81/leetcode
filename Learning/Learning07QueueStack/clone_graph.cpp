/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its
neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}


Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed).
For example, the first node with val == 1, the second node with val == 2, and so
on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite
graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the
copy of the given node as a reference to the cloned graph.



Example 1:


Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: There are 4 nodes in the graph.
1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
Example 2:


Input: adjList = [[]]
Output: [[]]
Explanation: Note that the input contains one empty list. The graph consists of
only one node with val = 1 and it does not have any neighbors. Example 3:

Input: adjList = []
Output: []
Explanation: This an empty graph, it does not have any nodes.


Constraints:

The number of nodes in the graph is in the range [0, 100].
1 <= Node.val <= 100
Node.val is unique for each node.
There are no repeated edges and no self-loops in the graph.
The Graph is connected and all nodes can be visited starting from the given
node.

*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 private:
  unordered_map<int, Node*> nodes_map;
  unordered_map<int, Node*> nodes_copy;
  vector<int> all_nodes;
  unordered_map<int, bool> lookup;

  void build_nodes(Node* node) {
    if (lookup[node->val]) return;

    lookup[node->val] = true;


    nodes_map[node->val] = node;
    nodes_copy[node->val] = new Node(node->val);
    all_nodes.push_back(node->val);

    vector<Node*> neigh = node->neighbors;
    for (Node* n : neigh) {
      if (!lookup[n->val]) {
        build_nodes(n);
      }
    }
  }

  void build_edges() {
    for (int ni : all_nodes) {
      for (Node* neighbor : nodes_map[ni]->neighbors) {
        nodes_copy[ni]->neighbors.push_back(nodes_copy[neighbor->val]);
      }
    }
  }

 public:
  Node* cloneGraph(Node* node) {
    // node val is unique, so visited map with vals good enough

    // clone with DFS
    if (!node) {
      return NULL;
    }

    if (node->neighbors.empty()) {
      return new Node(node->val);
    }

    build_nodes(node);

    build_edges();

    cerr << all_nodes.size() << endl;
    return nodes_copy[all_nodes.front()];
  }
};

void printR(Node* n, unordered_map<int, bool> visited) {
  if (visited[n->val]) return;

  cerr << "traversing " << n->val << endl;
  cerr << " neighbor size " << n->neighbors.size() << endl;
  visited[n->val] = true;
  for (Node* nn : n->neighbors) {
    if (!visited[nn->val]) {
      printR(nn, visited);
    }
  }
}

int main() {
  // [[2,4],[1,3],[2,4],[1,3]] failing test
  Node* n = new Node(1);  // New is a memory allocator, so we allocate a pointer
  Node* n2 = new Node(2);
  Node* n3 = new Node(3);
  Node* n4 = new Node(4);
  Solution s = Solution();
  vector<Node*> nneighbors;
  vector<Node*> n2neighbors;
  vector<Node*> n3n;
  vector<Node*> n4n;
  nneighbors.push_back(n2);
  nneighbors.push_back(n4);
  n2neighbors.push_back(n);
  n2neighbors.push_back(n3);
  n3n.push_back(n2);
  n3n.push_back(n4);
  n4n.push_back(n);
  n4n.push_back(n3);
  n->neighbors = nneighbors;
  n2->neighbors = n2neighbors;
  n3->neighbors = n3n;
  n4->neighbors = n4n;
  Node* x = n;

  Node* copyN = s.cloneGraph(n);
  cerr << "original " << endl;
  // printR(n, visited);
  cerr << "copy " << endl;
   // printR(copyN, visited);
  return 0;
}

/*

@nbolton Re: UPDATE 1 - One of the beautiful things about C++ is that it allows
you to store User Defined Types on the stack, whereas garbage collected langs
like C# force you to store the data on the heap. Storing data on the heap
consumes more resources than storing data on the stack, thus you should prefer
the stack to the heap, except when your UDT requires a large amount of memory to
store its data. (This also means that objects are passed by value by default). A
better solution to your problem would be passing the array to the function by
reference.
*/
