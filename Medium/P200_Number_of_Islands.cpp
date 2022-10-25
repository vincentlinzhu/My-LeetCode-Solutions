#include <iostream>
#include <vector>
#include <map>

using namespace std;

void dfs(vector< vector<char> >& grid, int i, int j) {
    if (i + 1 <= grid.size() - 1 && grid[i + 1][j] == '1') {
        grid[i + 1][j] = '0';
        dfs(grid, i + 1, j);
    }
    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
        grid[i - 1][j] = '0';
        dfs(grid, i - 1, j);
    }
    if (j + 1 <= grid[i].size() - 1 && grid[i][j + 1] == '1') {
        grid[i][j + 1] = '0';
        dfs(grid, i, j + 1);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
        grid[i][j - 1] = '0';
        dfs(grid, i, j - 1);
    }
}

int numIslands(vector< vector<char> >& grid) {
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                dfs(grid, i, j);
                result++;
            }
        }
    }
    return result;
}


int main() {
    vector< vector<char> > v = {
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}
    };

cout << numIslands(v) << endl;
    return 0;
}