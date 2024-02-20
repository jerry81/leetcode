class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        if (columnNumber <= 0)
            return "";

        std::string result;
        while (columnNumber > 0) {
            int remainder = (columnNumber - 1) % 26;
            char digit = 'A' + remainder;
            result = digit + result;
            columnNumber = (columnNumber - 1) / 26;
        }

        return result;
    }
};