//Visited Approach:
void dfs(vector<vector<int>>& image, int sr, int sc, int color, int startColor, set<pair<int, int>>& visited) {
    //base case: when you reach an edge or a cell that you have already visited.
    if (visited.count(pair<int, int>(sr + 1, sc)) == 0 && sr + 1 < image.size() && image[sr + 1][sc] == startColor) {
        visited.insert(pair<int, int>(sr + 1, sc));
        image[sr + 1][sc] = color;
        dfs(image, sr + 1, sc, color, startColor, visited);
    }
    if (visited.count(pair<int, int>(sr - 1, sc)) == 0 && sr - 1 >= 0 && image[sr - 1][sc] == startColor) {
        visited.insert(pair<int, int>(sr - 1, sc));
        image[sr - 1][sc] = color;
        dfs(image, sr - 1, sc, color, startColor, visited);
    }
    if (visited.count(pair<int, int>(sr, sc + 1)) == 0 && sc + 1 < image[sr].size() && image[sr][sc + 1] == startColor) {
        visited.insert(pair<int, int>(sr, sc + 1));
        image[sr][sc + 1] = color;
        dfs(image, sr, sc + 1, color, startColor, visited);
    }
    if (visited.count(pair<int, int>(sr, sc - 1)) == 0 && sc - 1 >= 0 && image[sr][sc - 1] == startColor) {
        visited.insert(pair<int, int>(sr, sc - 1));
        image[sr][sc - 1] = color;
        dfs(image, sr, sc - 1, color, startColor, visited);
    }
    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // run a dfs on all 4 directions
    int startColor = image[sr][sc];
    set<pair<int, int>> visited;
    visited.insert(pair<int, int>(sr, sc));
    image[sr][sc] = color;
    dfs(image, sr, sc, color, startColor, visited);
    return image;
}

//Check if startColor == color:
void dfs(vector<vector<int>>& image, int sr, int sc, int color, int startColor) {
    //base case: when you reach an edge or a cell that you have already visited.
    if (startColor == color) {
        return;
    }
    if (sr + 1 < image.size() && image[sr + 1][sc] == startColor) {
        image[sr + 1][sc] = color;
        dfs(image, sr + 1, sc, color, startColor);
    }
    if (sr - 1 >= 0 && image[sr - 1][sc] == startColor) {
        image[sr - 1][sc] = color;
        dfs(image, sr - 1, sc, color, startColor);
    }
    if (sc + 1 < image[sr].size() && image[sr][sc + 1] == startColor) {
        image[sr][sc + 1] = color;
        dfs(image, sr, sc + 1, color, startColor);
    }
    if (sc - 1 >= 0 && image[sr][sc - 1] == startColor) {
        image[sr][sc - 1] = color;
        dfs(image, sr, sc - 1, color, startColor);
    }
    
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    // run a dfs on all 4 directions
    int startColor = image[sr][sc];
    image[sr][sc] = color;
    dfs(image, sr, sc, color, startColor);
    return image;
}