class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            // Update heights for each row
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            // Calculate the largest rectangle in histogram for each row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            cout << "i is " << i << endl;
            while (!s.empty() && (i == n || heights[i] < heights[s.top()])) {
                int height = heights[s.top()];
                cout << "pop" << s.top() << endl;
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
             cout << "push" << i << endl;
            s.push(i);
        }

        return maxArea;
    }
};