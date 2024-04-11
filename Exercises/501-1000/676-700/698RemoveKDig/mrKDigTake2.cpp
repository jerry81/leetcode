
class Solution {
/* greedy */
// returns the indexes of digits to remove
vector<int> r(string remain, int k, int cur_idx) {
  // stop when k is 0
  cout << "remain " << remain << " k " << k << endl;
  if (k == 0) return {};
  if (remain.size() <= k) {
    vector<int> res = {};
    for (int i = cur_idx; i < remain.size(); ++i) {
      res.push_back(i);
      return res;
    }
  }

  // take it or leave it
  char first = remain[0];
  char second = remain[1];
  cout << "foist " << first << "second " << second << endl;
  if (first < second) {
    return r(remain.substr(1), k, cur_idx+1);
  } else if (first > second) {
    vector<int> res = {cur_idx};
    vector<int> use = r(remain.substr(1), k-1, cur_idx+1);
    res.insert(res.end(), use.begin(), use.end());
    return res;
  } else {
    // equal case, trying both would be slow.
    // look ahead to first non-repeat
    // this takes care of case where the next non-repeat is lessthan (then greedy remove first item)
    // but if non-repeat greater then must check how many ks remain.
    //  if ks remain
  }
  return {}; // never will reach here, right?
}