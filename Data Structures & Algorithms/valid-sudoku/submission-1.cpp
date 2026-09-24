class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> freq_rows[9];
        unordered_set<int> freq_cols[9];
        unordered_set<int> freq_squares[9];

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') continue;

                if(freq_rows[i].count(board[i][j]) || freq_cols[j].count(board[i][j]) || freq_squares[(i / 3) * 3 + (j / 3)].count(board[i][j])) {
                    return false;
                }

                freq_rows[i].insert(board[i][j]);
                freq_cols[j].insert(board[i][j]);
                freq_squares[(i / 3) * 3 + (j / 3)].insert(board[i][j]);
            }
        }

        return true;
    }
};
