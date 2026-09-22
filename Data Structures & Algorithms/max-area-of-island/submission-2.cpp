class Solution {
public:

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(int r, int c, int rows, int cols) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {

        int rows = grid.size();
        int cols = grid[0].size();

        if(!isValid(r, c, rows, cols) || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0;
        int current_area = 1;

        for(auto [dr, dc]: directions) {
            current_area += dfs(grid, r + dr, c + dc);
        }

        return current_area;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
               if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j));
               }
            }
        }

        return maxArea;
    }
};
