class Solution {
public:
    vector<vector<int>> spiralMatrixIII(
        int rows,
        int cols,
        int rStart,
        int cStart
    ) {
        
        vector<vector<int>> ans;

        vector<pair<int,int>> directions = {
            {0, 1},    // right
            {1, 0},    // down
            {0, -1},   // left
            {-1, 0}    // up
        };

        int r = rStart;
        int c = cStart;

        int steps = 1;
        int dir = 0;

        ans.push_back({r, c});

        while(ans.size() < rows * cols) {

            // Two directions have the same step count
            for(int repeat = 0; repeat < 2; repeat++) {

                for(int i = 0; i < steps; i++) {

                    r += directions[dir].first;
                    c += directions[dir].second;

                    // Add only if inside grid
                    if(r >= 0 && r < rows &&
                       c >= 0 && c < cols) {

                        ans.push_back({r, c});
                    }
                }

                dir = (dir + 1) % 4;
            }

            steps++;
        }

        return ans;
    }
};