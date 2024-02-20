class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        int power = 0;

        for (int i = columnTitle.size() - 1; i >= 0; --i) {
            char c = columnTitle[i];
            int append = pow(26, power) * (c - 'A' + 1);
            sum += append;
            power++;
        }

        return sum;
    }
};