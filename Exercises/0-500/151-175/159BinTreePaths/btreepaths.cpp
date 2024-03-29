class Solution {
vector<string> paths;
string toS(vector<int> inp) {
  bool first = true;
  string ret = "";
  for (int i:inp) {
    if (first) {
      ret+=to_string(i);
      first = false;
    } else {
      ret+="->";
      ret+=to_string(i);
    }
  }
  return ret;
}
void t(TreeNode* root, vector<int> curPath) {
  if (root == nullptr) return;

  curPath.push_back(root->val);
  if (root->left == nullptr && root->right==nullptr) paths.push_back(toS(curPath));
  t(root->left, curPath);
  t(root->right, curPath);
}
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      vector<int> empty;
      t(root, empty);
      return paths;
    }
};