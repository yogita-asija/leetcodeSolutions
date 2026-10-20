class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Start or destination is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        // Mark starting cell as visited
        grid[0][0] = 1;

        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        int pathLength = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                // Destination reached
                if (r == n - 1 && c == n - 1) {
                    return pathLength;
                }

                for (auto& d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    // Check bounds and whether cell is unvisited
                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 0) {

                        q.push({nr, nc});

                        // Mark visited when adding to queue
                        grid[nr][nc] = 1;
                    }
                }
            }

            pathLength++;
        }

        return -1;
    }
};