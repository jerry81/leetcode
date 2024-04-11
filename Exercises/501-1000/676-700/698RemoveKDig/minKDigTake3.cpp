#include <string>

using namespace std;

// takeaway: review monotonic stack
// nonotinic stack good for these "smallest or largest integer" through string manipulation

class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        int keep = num.size() - k;

        // Greedily build the result string, removing digits as needed
        for (char digit : num) { // left to right iteration
            while (k > 0 && !result.empty() && result.back() > digit) { //
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        // Remove remaining digits if necessary
        result.resize(keep);

        // Remove leading zeros
        int i = 0;
        while (i < result.size() && result[i] == '0') {
            i++;
        }

        return i == result.size() ? "0" : result.substr(i);
    }
};