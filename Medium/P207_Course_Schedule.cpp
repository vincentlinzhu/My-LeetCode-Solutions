bool dfs(int v, unordered_map<int, vector<int>>& g, unordered_set<int>& s) {
    if (s.find(v) != s.end()) {
        return false;
    }

    if (g[v].empty()) {
        return true;
    }

    s.insert(v);

    for (int i = 0; i < g[v].size(); i++) {
        int next = g[v][i];
        if (!dfs(next, g, s)) {
            return false;
        }
    }

    g[v].clear();
    s.erase(v);
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // Build adjacency list
    // Run topological sort
    // If sort is possible (you only visit a node once and get through all the nodes) return true
    // Essentially, are there any cycles
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < numCourses; i++) {
        g[i] = vector<int>();
    }
    
    for (int i = 0; i < prerequisites.size(); i++) {
        g[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }

    unordered_set<int> s;
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, g, s)) {
            return false;
        }
    }

    return true;
}