#include <vector>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      vector<int> sorted = deck;
      sort(sorted.begin(), sorted.end());
      vector<int> res;
      while (!sorted.empty()) {
        int bk = sorted.back();
        sorted.pop_back();

        if (!deck.empty()) {
          int resbk = res.back();
          res.pop_back();
          res.insert(res.begin(), resbk);
          res.insert(res.begin(), bk);
        } else {
          res.push_back(bk);
        }
      }
      return res;
    }
};