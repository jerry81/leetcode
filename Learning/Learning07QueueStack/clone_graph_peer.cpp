class Solution {
public:
	void dfscopy(Node * node, Node * copy,vector<Node*> &vis) // vector used as visited
	{
	  vis[copy->val]=copy; // vector can use array notation
	  for(auto x:node->neighbors) // auto typing?
	  {

		if(vis[x->val]==NULL) // not already visited
		{
		  Node * newNode =new Node(x->val);
		  (copy->neighbors).push_back(newNode);
		  dfscopy(x,newNode,vis); // recurse
		}

		else
		{ // already visited
		  (copy->neighbors).push_back(vis[x->val]); // still must add to neighbors (from visited map)
		}
	  }
	}

	Node* cloneGraph(Node* node)
	{
	  if(node==NULL)
	  {
		return NULL;
	  }
	  vector<Node *> vis(1000,NULL);
	  Node * copy =new Node(node->val);
	  dfscopy(node,copy,vis);
	  return copy;
	}
};