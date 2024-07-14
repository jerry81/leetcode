
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> atomCount;
        stack<map<string, int>> stk;
        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                stk.push(map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                map<string, int> top = stk.top();
                stk.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplier = i > start ? stoi(formula.substr(start, i - start)) : 1;
                for (auto& p : top) {
                    p.second *= multiplier;
                }
                if (!stk.empty()) {
                    for (auto& p : top) {
                        stk.top()[p.first] += p.second;
                    }
                } else {
                    for (auto& p : top) {
                        atomCount[p.first] += p.second;
                    }
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string atom = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = i > start ? stoi(formula.substr(start, i - start)) : 1;
                if (!stk.empty()) {
                    stk.top()[atom] += count;
                } else {
                    atomCount[atom] += count;
                }
            }
        }

        // Convert map to string output
        string result;
        for (auto& p : atomCount) {
            result += p.first;
            if (p.second > 1) {
                result += to_string(p.second);
            }
        }
        return result;
    }
};