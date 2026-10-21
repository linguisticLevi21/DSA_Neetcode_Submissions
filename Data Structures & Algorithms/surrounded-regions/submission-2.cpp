class Solution {
public:
typedef pair<int, int> p;
    vector<vector<int>> directions = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        if(m == 1 || n == 1) return;

        queue<p> q;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '&';
                q.push({i, 0});
            }

            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '&';
                q.push({i, n - 1});
            }
        }

        // First and last row
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') {
                board[0][j] = '&';
                q.push({0, j});
            }

            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '&';
                q.push({m - 1, j});
            }
        }

        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto &dir : directions)
                {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx>=0 && ny >= 0 && nx<m && ny<n && board[nx][ny] == 'O')
                    {
                        board[nx][ny] = '&';
                        q.push({nx,ny});
                    }
                }
            }
        }
        for(int i = 0 ; i < m ; i++)
            {
                for(int j = 0 ; j < n ; j++)
                {
                    if(board[i][j] == '&')
                    {
                        board[i][j] = 'O';
                    }
                    else
                    {
                        board[i][j] = 'X';
                    }
                }
            }

    }
};
