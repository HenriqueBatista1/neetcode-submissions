class Solution {
public:

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(int r, int c, int rows, int cols) {
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int maxArea = 0;
        int area = 0;

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;
                    q.push({i, j});
                    area++;

                    while(!q.empty()) {
                        auto [r, c] = q.front();

                        q.pop();

                        for(auto [dr, dc] : directions) {
                            int nr = r + dr;
                            int nc = c + dc;

                            if(isValid(nr, nc, rows, cols) && grid[nr][nc] == 1) {
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                                area++;
                            }
                        }
                    }
                    maxArea = max(maxArea, area);
                    area = 0;
                }
            }
        }

        return maxArea;
    }
};
