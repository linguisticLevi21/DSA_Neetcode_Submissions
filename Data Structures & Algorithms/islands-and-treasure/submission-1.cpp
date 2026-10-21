class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    typedef pair<int, int> p;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int inf = 2147483647;

        if (grid.empty() || grid[0].empty()) return;

        int m = grid.size();
        int n = grid[0].size();

        queue<p> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int s = q.size();
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto& dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                        grid[nx][ny] == inf) {

                        grid[nx][ny] = grid[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        
    }
};