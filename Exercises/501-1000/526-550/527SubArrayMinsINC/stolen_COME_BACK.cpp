#include <vector>
#include <stack>
#include <cmath>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = pow(10,9) + 7;
        stack<int> st;
        long sumOfMinimums = 0;

        for (int i = 0; i <= arr.size(); i++) {
            // stack holds arr indexes (smallest idxes at bottom of stack)
            // empty -> handles start
            // special case - i == size
            // comparison of values -> previous items pushed to stack and current i
            while (!st.empty() && (i == arr.size() || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                int leftBoundary = st.empty() ? -1 : st.top(); // some off-by-one magic
                int rightBoundary = i;

                // number of items to left * number of items to right
                long count = (mid - leftBoundary) * (rightBoundary - mid) % MOD;
                // so these are count of subarrays with arr[mid] as the min
                // not sure why
                sumOfMinimums += (count * arr[mid]) % MOD;
                sumOfMinimums %= MOD;
            }
            st.push(i);
        }

        return static_cast<int>(sumOfMinimums);
    }
};
