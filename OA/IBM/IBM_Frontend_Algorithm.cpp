int minNumberOfMachines(int n, vector<int>& start, vector<int>& end) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back(pair<int, int>(start[i], end[i]));
    }
    // sort intervals by start time
    sort(v.begin(), v.end());
    
    // min heap to track min end time of merged intervals
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);
    
    for (int i = 1; i < v.size(); i++) {
        // compare curr start w/ earliest end time, if no overlap then pop
        if (v[i].first >= pq.top()) {
            pq.pop();
        }
        // add new room (will replace/be same size if above was true)
        pq.push(v[i].second);
    }
    
    return pq.size();
}