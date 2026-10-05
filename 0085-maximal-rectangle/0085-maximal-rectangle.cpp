class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;
        int maxArea = 0;

        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {

                int h = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        heights.pop_back();

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int ans = 0;

        for (int i = 0; i < rows; i++) {

            // Update heights
            for (int j = 0; j < cols; j++) {

                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            // Largest Rectangle in Histogram
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};