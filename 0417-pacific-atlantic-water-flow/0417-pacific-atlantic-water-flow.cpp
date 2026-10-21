
class Solution {
public:
    int m, n;
    vector<vector<int>> pacific, atlantic;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<int>>& vis) {
        vis[r][c] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (vis[nr][nc])
                continue;

            if (heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(
        vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        pacific.assign(m, vector<int>(n, 0));
        atlantic.assign(m, vector<int>(n, 0));

        for (int c = 0; c < n; c++) {
            dfs(0, c, heights, pacific);
            dfs(m - 1, c, heights, atlantic);
        }

        for (int r = 0; r < m; r++) {
            dfs(r, 0, heights, pacific);
            dfs(r, n - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    ans.push_back({r, c});
                }
            }
        }

        return ans;
    }
};
