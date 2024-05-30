
#include <vector>

using namespace std;

/*

keys:
1.  xor something twice is idempotent
2.  use prefixXor array as our memo
3.  reduce the 3 loops into two

*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        int sz = arr.size();

        // Compute prefix XOR
        vector<int> prefixXOR(sz + 1, 0);
        for (int i = 0; i < sz; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        // Count triplets
        for (int i = 0; i < sz; ++i) {
            for (int k = i + 1; k < sz; ++k) {
                // If the XOR from arr[i] to arr[j-1] is equal to the XOR from arr[j] to arr[k]
                // it means prefixXOR[i] == prefixXOR[k+1]
                if (prefixXOR[i] == prefixXOR[k + 1]) {
                    count += (k - i);
                }
            }
        }

        return count;
    }
};