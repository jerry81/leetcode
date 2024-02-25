#include <vector>

using namespace std;
vector<int> eratosthenes(int MAX) {
  vector<int> sieve(MAX + 1, 0);
  for (int d = 2; d <= MAX; d++) {
    if (sieve[d] == 0) {
      for (int v = d; v <= MAX; v += d) {
        sieve[v] = d;
      }
    }
  }
  return sieve;
}