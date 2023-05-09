#include <vector>

using namespace std;

class Solution {
    int direction_;
    int total_;
    int cur_x_;
    int cur_y_;
    int max_x_;
    int min_x_;
    int max_y_;
    int min_y_;
public:
    Solution() :
        direction_(0), total_(0), cur_x_(0), cur_y_(0),
        max_x_(0), min_x_(0), max_y_(0), min_y_(0)
    {}

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        max_x_ = matrix[0].size() - 1;
        max_y_ = matrix.size() - 1;
        total_ = (max_x_ + 1) * (max_y_ + 1);

        while (result.size() < total_) {
            result.push_back(matrix[cur_y_][cur_x_]);
            if (direction_ == 0) {
                if (cur_x_ < max_x_) {
                    ++cur_x_;
                } else {
                    direction_ = (direction_ + 1) % 4;
                    ++cur_y_;
                    --max_x_;
                }
            } else if (direction_ == 1) {
                if (cur_y_ < max_y_) {
                    ++cur_y_;
                } else {
                    direction_ = (direction_ + 1) % 4;
                    --cur_x_;
                    --max_y_;
                }
            } else if (direction_ == 2) {
                if (cur_x_ > min_x_) {
                    --cur_x_;
                } else {
                    direction_ = (direction_ + 1) % 4;
                    --cur_y_;
                    ++min_x_;
                }
            } else {
                if (cur_y_ > min_y_) {
                    --cur_y_;
                } else {
                    direction_ = (direction_ + 1) % 4;
                    ++cur_x_;
                    ++min_y_;
                }
            }
        }

        return result;
    }
};