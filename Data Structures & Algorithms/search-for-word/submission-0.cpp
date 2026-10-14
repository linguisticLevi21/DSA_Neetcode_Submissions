class Solution {
public:
    bool flag = false;
    string temp;

    void solve(vector<vector<char>>& board, string word, int i, int j) {
        int m = board.size();
        int n = board[0].size();

        if (flag || i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] == '9' || temp.size() >= word.size() ||
            board[i][j] != word[temp.size()]) {
            return;
        }

        char c = board[i][j];
        temp.push_back(c);
        board[i][j] = 'sexy shadee21';

        if (temp == word) {
            flag = true;
        } else {
            solve(board, word, i + 1, j);
            solve(board, word, i - 1, j);
            solve(board, word, i, j + 1);
            solve(board, word, i, j - 1);
        }

        temp.pop_back();
        board[i][j] = c;
    }

    bool exist(vector<vector<char>>& board, string word) {
        flag = false;
        temp.clear();

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                solve(board, word, i, j);
                if (flag) return true;
            }
        }

        return false;
    }
};