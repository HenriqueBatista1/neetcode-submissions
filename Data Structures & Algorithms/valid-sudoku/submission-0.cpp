class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> squares[9];


        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                int val = board[i][j];

                if(val == '.') continue;

                int square_index = (i / 3) * 3 + (j / 3);

                if(rows[i].count(val) || cols[j].count(val) || squares[square_index].count(val))
                {
                    return false;
                }

                rows[i].insert(val);
                cols[j].insert(val);
                squares[square_index].insert(val);
            }
        }

        return true;
    }
};
