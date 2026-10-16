class Solution {
public:
    typedef pair<int, int> p;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]=='0') return;
        grid[i][j] = '0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid.empty()) return 0;
       // vector<vector<int>> vis(m, vector<int>(n, 0));
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid);
                    // vis[i][j] = true;
                }
            }
        }
        return cnt;
    }
};