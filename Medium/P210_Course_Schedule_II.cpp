vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;

    vector<int> classes(numCourses, -1);
    for (int i = 0; i < numCourses; i++) {
        classes[i] = i;
    }

    unordered_map<int, unordered_set<int>> indegree;
    unordered_map<int, vector<int>> outdegree;
    for (int i = 0; i < prerequisites.size(); i++) {
        classes[prerequisites[i][0]] = -1;
        //make indegree
        if (indegree.count(prerequisites[i][0])) {
            indegree[prerequisites[i][0]].insert(prerequisites[i][1]);
        } else {
            unordered_set<int> s;
            s.insert(prerequisites[i][1]);
            indegree[prerequisites[i][0]] = s;
        }

        //make outdegree
        if (outdegree.count(prerequisites[i][1])) {
            outdegree[prerequisites[i][1]].push_back(prerequisites[i][0]);
        } else {
            vector<int> v;
            v.push_back(prerequisites[i][0]);
            outdegree[prerequisites[i][1]] = v;
        }
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (classes[i] != -1) {
            q.push(classes[i]);
        }
    }

    while (!q.empty()) {
        for (auto x : outdegree[q.front()]) {
            indegree[x].erase(q.front());
            if (indegree[x].empty()) {
                indegree.erase(x);
                q.push(x);
            }
        }

        res.push_back(q.front());
        q.pop();
    }


    if (indegree.empty()) {
        return res;
    }

    return {};
}