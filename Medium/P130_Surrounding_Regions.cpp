void dfs(vector<vector<char>>& board, int i, int j) {
    if ((i < 0 || j < 0) || (i == board.size() || j == board[i].size()) || (board[i][j] != 'O')) {
        return;
    }
    board[i][j] = 'T';
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
}

void solve(vector<vector<char>>& board) {
    // post order = flip after doing the dfs
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'O' && ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1))) {
                dfs(board, i, j);
            }
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'O') board[i][j] = 'X';
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'T') board[i][j] = 'O';
        }
    }
}