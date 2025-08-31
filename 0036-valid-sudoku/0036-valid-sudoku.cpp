// class Solution {
// public:
//     bool check(int num, vector<vector<char>>& board, int i, int j) {
//         char c = '0' + num;
//         for (int col = 0; col < 9; col++) {
//             if (board[i][col] == c) return false;
//         }
//         for (int row = 0; row < 9; row++) {
//             if (board[row][j] == c) return false;
//         }
//         // check at same box
//         int row = i / 3 * 3, col = j / 3 * 3;
//         for (int a = row; a < row + 3; a++) {
//             for (int b = col; b < col + 3; b++) {
//                 if (board[a][b] == c) return false;
//             }
//         }
//         return true;
//     }

//     bool find(vector<vector<char>>& board, int i, int j) {
//         if (i == 9) return true;
//         if (j == 9) return find(board, i + 1, 0);
//         if (board[i][j] != '.') return find(board, i, j + 1);

//         // try all numbers 1–9
//         for (int num = 1; num <= 9; num++) {
//             if (check(num, board, i, j)) {
//                 board[i][j] = '0' + num;
//                 if (find(board, i, j + 1)) return true;
//                 board[i][j] = '.';
//             }
//         }
//         return false;
//     }

//     bool isValidSudoku(vector<vector<char>>& board) {
//         return find(board, 0, 0);
//     }
// };
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // use sets to track seen numbers
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue; // skip empty cells

                // check row
                if (rows[i].count(c)) return false;
                rows[i].insert(c);

                // check col
                if (cols[j].count(c)) return false;
                cols[j].insert(c);

                // check 3x3 box
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(c)) return false;
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};

