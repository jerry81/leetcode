class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = -1, di = 0, dj = 1;
        for (int k = 0; k < m * n; ++k) {
            result.push_back(matrix[i][j]);
            matrix[i][j] = -101; // mark as visited
            if (matrix[(i + di + m) % m][(j + dj + n) % n] == -101) {
                swap(di, dj);
                dj = -dj; // rotate direction
            }
            i += di, j += dj;
        }
        return result;
    }
};