class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // if(grid[i][j]=='1') return 1;
        if (i <0  || i >=m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;
        grid[i][j] = 0;
        int found = 1 + dfs(i + 1, j, grid)+
        dfs(i - 1, j, grid)+
        dfs(i, j + 1, grid)+
        dfs(i, j - 1, grid);
        return found;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
       // cout<<dfs(0,0,grid);
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt = dfs(i,j,grid);
                    ans = max(cnt, ans);
                    cout<<cnt<<" ";
                } else {
                   
                    cnt = 0;
                }
            }
        }
        return ans;
    }
};