class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows = true;
        bool cols = true;
        bool submatrix = true; // Variable name match hona chahiye

        // 1. Check Rows
        for(int i = 0; i < 9; i++) {
            unordered_set<char> s1;
            for(int j = 0; j < 9; j++) {
                char val = board[i][j];
                if(val == '.') continue;
                if(s1.count(val)) {
                    rows = false;
                }
                s1.insert(val);
            }
        }

        // 2. Check Columns
        for(int j = 0; j < 9; j++) {
            unordered_set<char> s2;
            for(int i = 0; i < 9; i++) {
                char val = board[i][j]; // Column fix, row change
                if(val == '.') continue;
                if(s2.count(val)) {
                    cols = false;
                }
                s2.insert(val);
            }
        }

        // 3. Check 3x3 Submatrices (Total 9 boxes hote hain)
        for(int box = 0; box < 9; box++) {
            unordered_set<char> s3;
            // Har box ka starting row aur column nikalne ka formula
            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;

            for(int r = 0; r < 3; r++) {
                for(int c = 0; c < 3; c++) {
                    char val = board[startRow + r][startCol + c];
                    if(val == '.') continue;
                    if(s3.count(val)) {
                        submatrix = false;
                    }
                    s3.insert(val);
                }
            }
        }

        return rows && cols && submatrix;
    }
};