#include <vector>
using namespace std;

class Solution {
public:
    int rows, cols;
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc] &&heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if (heights.empty() || heights[0].empty()) return result;

        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int c = 0; c < cols; c++) dfs(heights, pacific, 0, c);
        for (int r = 0; r < rows; r++) dfs(heights, pacific, r, 0);

        for (int c = 0; c < cols; c++) dfs(heights, atlantic, rows - 1, c);
        for (int r = 0; r < rows; r++) dfs(heights, atlantic, r, cols - 1);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
