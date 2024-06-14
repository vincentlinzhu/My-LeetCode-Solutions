bool isValidSudoku(vector<vector<char>>& board) {
    // travers the board
    // mark the location of each number
    //rows
    unordered_set<char> s_row;
    for (auto row : board) {
        for (auto pos : row) {
            if (pos != '.' && s_row.find(pos) != s_row.end()) {
                return false;
            } else {
                s_row.insert(pos);
            }
        }
        s_row.clear();
    } 

    //columns
    unordered_set<char> s_column;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][i] != '.' && s_column.find(board[j][i]) != s_column.end()) {
                return false;
            } else {
                s_column.insert(board[j][i]);
            }
        }
        s_column.clear();
    } 

    //ninths
    unordered_set<char> s_ninths;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 6; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();
    for (int i = 0; i < 3; i++) {
        for (int j = 6; j < 9; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();
    for (int i = 3; i < 6; i++) {
        for (int j = 3; j < 6; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();
    for (int i = 3; i < 6; i++) {
        for (int j = 6; j < 9; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();
    for (int i = 6; i < 9; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();
    for (int i = 6; i < 9; i++) {
        for (int j = 3; j < 6; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();
    for (int i = 6; i < 9; i++) {
        for (int j = 6; j < 9; j++) {
            if (board[i][j] != '.' && s_ninths.find(board[i][j]) != s_ninths.end()) {
                return false;
            } else {
                s_ninths.insert(board[i][j]);
            }
        }
    } 
    s_ninths.clear();

    return true;
}