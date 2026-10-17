class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> q;
        int fresh = 0;

        // push all rotten
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }

        int minutes = 0;

        while(!q.empty() && fresh > 0){
            int size = q.size();
            minutes++;

            while(size--){
                auto [x,y] = q.front(); q.pop();

                for(auto &dir : directions){
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }

        return fresh == 0 ? minutes : -1;
    }
};