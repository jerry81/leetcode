
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    vector<string> res;

    void r(int idx, vector<string> &accum, string &s, unordered_set<string> &words, int sz) {
        if (idx == sz) {
            // If we've reached the end of the string, add the current accumulation to results
            string sentence;
            for (int i = 0; i < accum.size(); ++i) {
                if (i > 0) sentence += " ";
                sentence += accum[i];
            }
            res.push_back(sentence);
            return;
        }

        // Try to partition the string at different positions
        for (int i = idx; i < sz; ++i) {
            string word = s.substr(idx, i - idx + 1);
            if (words.find(word) != words.end()) {
                accum.push_back(word); // Add the current word to the accumulation
                r(i + 1, accum, s, words, sz); // Recurse with the new starting index
                accum.pop_back(); // Backtrack
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<string> accum;
        r(0, accum, s, words, s.size());
        return res;
    }
};