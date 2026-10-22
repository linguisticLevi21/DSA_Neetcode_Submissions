class Solution {
   public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int m, n;
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& heights, int prev) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (heights[i][j] < prev || vis[i][j]) return;

        vis[i][j] = true;

        for (auto& dir : directions) {
            int nx = i + dir[0];
            int ny = j + dir[1];

            dfs(nx, ny, vis, heights, heights[i][j]);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, (vector<bool>(n, false)));
        vector<vector<bool>> atl(m, (vector<bool>(n, false)));

        // for(int i = 0 ; i < m ; i++)
        // {
        //     dfs(0,i,pac,heights,INT_MIN);
        //     dfs(n-1,i,atl,heights,INT_MIN);
        // }

        // for(int i = 0 ; i < n ; i++)
        // {
        //     dfs(i,0,atl,heights,INT_MIN);
        //     dfs(i,m-1,pac,heights,INT_MIN);
        // }
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            dfs(i, 0, pac, heights, INT_MIN);      // Pacific: left
            dfs(i, n - 1, atl, heights, INT_MIN);  // Atlantic: right
        }

        for (int j = 0; j < n; j++) {
            dfs(0, j, pac, heights, INT_MIN);      // Pacific: top
            dfs(m - 1, j, atl, heights, INT_MIN);  // Atlantic: bottom
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
