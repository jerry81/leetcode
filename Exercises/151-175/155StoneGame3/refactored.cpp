class Solution {
private:
    vector<vector<int>> lookup;
    int size;
    vector<int> piles;

    int r(int turn, int head) {
        if (head >= size) return 0;
        if (lookup[turn][head] > INT_MIN) return lookup[turn][head];

        int res = (turn == 0) ? INT_MIN : INT_MAX;
        int sum = 0;

        for (int i = 1; i <= min(size - head, 3); ++i) {
            int idx = i + head;
            sum += piles[idx - 1];

            if (turn == 0) {
                res = max(res, sum + r(1, idx));
            } else {
                res = min(res, r(0, idx));
            }
        }

        return lookup[turn][head] = res;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        size = stoneValue.size();
        piles = stoneValue;
        lookup.resize(2, vector<int>(size + 1, INT_MIN)); // cool trick to "init the member"

        int alice = r(0, 0);
        int bob = accumulate(stoneValue.begin(), stoneValue.end(), 0) - alice; // sum

        if (alice > bob) return "Alice";
        if (alice < bob) return "Bob";
        return "Tie";
    }
};