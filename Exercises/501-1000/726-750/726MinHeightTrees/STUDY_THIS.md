Simpler || Faster || Fully Explained

priyasmb24
Top SQL 50
32
77
2 hours ago
Java
Python
Python3
C#
6+
Intuition
Keep the list of adjacency nodes for each node.
Keep the list of leaf nodes, where adjCount == 1
Update the list by traversing the leaf nodes and updating them in the adjacency list
Update the leaf nodes list with new leaves, till remaining nodes are > 2.

Here's why the condition is remainingNodes > 2:

Case of one node left (n = 1):
    If there is only one node in the tree, it is already the root of the minimum height tree, and there are no other nodes to consider. In this case, we return the single node as the result.

Case of two nodes left (n = 2):
    If there are only two nodes left, they are connected by an edge, and both nodes are roots of the minimum height trees. This is because the height of a tree with two nodes is 1 (the distance between the two nodes), and there are no other nodes that can be added to minimize the height further.

Case of more than two nodes left (n > 2):
    If there are more than two nodes left, we continue the removal process. At each step, we remove the current leaf nodes (nodes with only one neighbor) and update their neighbors. This process continues until there are either one or two nodes left, as explained above.
Approach
The approach to find the minimum height trees (MHTs) in a graph is based on the idea of iteratively removing leaf nodes (nodes with only one neighbor) from the graph until only one or two nodes remain. The remaining nodes are then considered as the roots of the MHTs.

Here's a step-by-step explanation of the approach:

Build the Adjacency List:
Create an adjacency list to represent the graph. Each node in the graph is a key in the adjacency list, and the corresponding value is a set of its neighboring nodes.

Find the Leaf Nodes:
Identify all the leaf nodes in the graph (nodes with only one neighbor) and add them to a list.

Remove Leaves Iteratively:
Continue the following steps until there are only one or two nodes left in the graph:
    Remove all the current leaf nodes from the graph by removing the edges between the leaf nodes and their neighbors.
    Update the neighbor nodes of the removed leaf nodes (by removing the removed leaf nodes from their neighbor lists).
    Identify the new leaf nodes (nodes that become leaf nodes after the removal of the current leaf nodes) and add them to the list of leaves for the next iteration.

Return the Remaining Nodes:
After the iteration, the remaining one or two nodes are the roots of the minimum height trees in the graph.
By iteratively removing the leaf nodes and updating the graph, we gradually reduce the height of the tree until we are left with the minimum height trees.

image.png

image.png

Complexity
Time complexity: O(n)
Space complexity: O(n)
Code
public class Solution {
    public IList<int> FindMinHeightTrees(int n, int[][] edges) {
        // If there is only one node, return it as the root of the minimum height tree
        if (n == 1) {
            return new List<int>{0};
        }

        // Create an adjacency list to represent the graph
        var adjList = new List<int>[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new List<int>();
        }

        // Populate the adjacency list based on the edges
        foreach (var edge in edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].Add(v);
            adjList[v].Add(u);
        }

        // Find all leaf nodes (nodes with only one neighbor) as the starting point
        var leaves = new List<int>();
        for (int i = 0; i < n; i++) {
            if (adjList[i].Count == 1) {
                leaves.Add(i);
            }
        }

        // Keep track of the remaining nodes to process
        int remainingNodes = n;

        // Continue until there are only 1 or 2 nodes left
        while (remainingNodes > 2) {
            // Reduce the remaining nodes by the number of current leaf nodes
            remainingNodes -= leaves.Count;

            // Create a new list to store the new leaf nodes for the next iteration
            var newLeaves = new List<int>();

            // Remove current leaf nodes and update their neighbors
            foreach (var leaf in leaves) {
                int neighbor = adjList[leaf][0];
                adjList[neighbor].Remove(leaf);

                // If the neighbor becomes a leaf node, add it to the new leaves list
                if (adjList[neighbor].Count == 1) {
                    newLeaves.Add(neighbor);
                }
            }

            // Update the current leaf nodes for the next iteration
            leaves = newLeaves;
        }

        // At this point, the remaining nodes are the centers of the minimum height trees
        return leaves;
    }
}