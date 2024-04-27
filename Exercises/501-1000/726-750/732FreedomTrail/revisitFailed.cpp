class Solution {
  // memo on kidx,ringpos?
  vector<unordered_map<char, vector<pair<int, int>>>> lookup;
  vector<vector<int>> memo;
  int r(string& ring, string& key, int& sz, int kidx, int ringpos) {
    if (kidx >= sz) return 0;  // end.  no more characters to spell
    if (memo[ringpos][kidx] > -1) return memo[ringpos][kidx];
    char nxt = key[kidx];
    // try all the possibilities
    int mn = 999999999;
    auto mp = lookup[ringpos][nxt];
    for (auto [dist, nxtRP] : mp) {
      mn = min(mn, dist + 1 + r(ring, key, sz, kidx + 1, nxtRP));
    }
    memo[ringpos][kidx] = mn;
    return mn;
  }

 public:
  int findRotateSteps(string ring, string key) {
    /*
    godding
    (0)g: { g: 0, 1,  o: 1, d: 2, 3 i: 3, n: 2}
    */

    int sz = ring.size();
    lookup.resize(sz);
    int sz2 = key.size();
    memo.resize(sz, vector<int>(sz2, -1));
    // precalc distances
    for (int i = 0; i < sz; ++i) {
      char cur = ring[i];
      int dist = 0;
      pair<int, int> pr = {dist, i};
      lookup[i][cur].push_back(pr);
      int addend = 1;
      int lower = -1;
      int upper = -1;
      while (true) {
        lower = i - addend;
        if (lower < 0) lower += sz;
        char lc = ring[lower];
        if (lower == upper) break;
        lookup[i][lc].push_back({addend, lower});
        // process lower
        upper = i + addend;
        if (upper >= sz) upper%=sz;
        char uc = ring[upper];
        if (lower == upper) break;
        // process upper
        lookup[i][uc].push_back({addend, upper});
        addend += 1;
      }
    }
    // for (int i = 0; i < sz; ++i) {
    //   auto mp = lookup[i];
    //   cout << "from idx " << i << endl;
    //   for (auto [c, v] : mp) {
    //     cout << "dist to " << c << endl;
    //     for (auto [a, b] : v) {
    //       cout << a << " with idx " << b << endl;
    //     }
    //   }
    // }
    // we now spell the fucker with recursion/dp
    return r(ring, key, sz2, 0, 0);
  }
};