bool dfs(vector<vector<char>>& board, string word, int i, int j, string& curr_word, vector<vector<bool>>& visited) {
    if (curr_word == word) {
        return true;
    }

    if (i + 1 < board.size() && visited[i + 1][j] != true) {
        if (curr_word + board[i + 1][j] == word.substr(0, curr_word.size() + 1)) {
            curr_word += board[i + 1][j];
            visited[i + 1][j] = true;
            if(dfs(board, word, i + 1, j, curr_word, visited)) {
                return true;
            }
            curr_word.pop_back();
            visited[i + 1][j] = false;
        }
    }

    if (i - 1 >= 0 && visited[i - 1][j] != true) {
        if (curr_word + board[i - 1][j] == word.substr(0, curr_word.size() + 1)) {
            curr_word += board[i - 1][j];
            visited[i - 1][j] = true;
            if(dfs(board, word, i - 1, j, curr_word, visited)) {
                return true;
            }
            curr_word.pop_back();
            visited[i - 1][j] = false;
        }
    }

    if (j + 1 < board[0].size() && visited[i][j + 1] != true) {
        if (curr_word + board[i][j + 1] == word.substr(0, curr_word.size() + 1)) {
            curr_word += board[i][j + 1];
            visited[i][j + 1] = true;
            if(dfs(board, word, i, j + 1, curr_word, visited)) {
                return true;
            }
            curr_word.pop_back();
            visited[i][j + 1] = false;
        }
    }

    if (j - 1 >= 0 && visited[i][j - 1] != true) {
        if (curr_word + board[i][j - 1] == word.substr(0, curr_word.size() + 1)) {
            curr_word += board[i][j - 1];
            visited[i][j - 1] = true;
            if(dfs(board, word, i, j - 1, curr_word, visited)) {
                return true;
            }
            curr_word.pop_back();
            visited[i][j - 1] = false;
        }
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    // find the first letter and do a dfs from there
    // recursively call on the word minus the first letter each time
    string firstLetter;
    firstLetter += word[0];

    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    vector<pair<int, int>> startingPos;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == word[0]) {
                startingPos.push_back(pair<int, int>(i, j));
            }
        }
    }

    if (startingPos.size() == 0) {
        return false;
    }

    for (int k = 0; k < startingPos.size(); k++) {
        visited[startingPos[k].first][startingPos[k].second] = true;
        if (dfs(board, word, startingPos[k].first, startingPos[k].second, firstLetter, visited)) {
            return true;
        }
        visited[startingPos[k].first][startingPos[k].second] = false;
    }
    
    return false;
}