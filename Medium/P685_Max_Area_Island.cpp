void dfs(vector<vector<int>>& grid, int i, int j, int& area, set<pair<int, int>>& visited) {
    visited.insert(pair<int, int>(i, j));
    area++;
    if (i + 1 < grid.size() && grid[i + 1][j] == 1 && visited.count(pair<int, int>(i + 1, j)) == 0) {
        dfs(grid, i + 1, j, area, visited);
    }
    if (i - 1 >= 0 && grid[i - 1][j] == 1 && visited.count(pair<int, int>(i - 1, j)) == 0) {
        dfs(grid, i - 1, j, area, visited);
    }
    if (j + 1 < grid[i].size() && grid[i][j + 1] == 1 && visited.count(pair<int, int>(i, j + 1)) == 0) {
        dfs(grid, i, j + 1, area, visited);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == 1 && visited.count(pair<int, int>(i, j - 1)) == 0) {
        dfs(grid, i, j - 1, area, visited);
    }
    return;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    // interate through the grid until you find a 1, then use a dfs to add up the areas
    // make sure to keep a visited set
    set<pair<int, int>> visited;
    int maxArea = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (visited.count(pair<int, int>(i, j))) {
                continue;
            }
            if (grid[i][j] == 1) {
                int tempArea = 0;
                dfs(grid, i, j, tempArea, visited);
                maxArea = max(tempArea, maxArea);
            }
            visited.insert(pair<int, int>(i, j));
        }
    }
    return maxArea;
}