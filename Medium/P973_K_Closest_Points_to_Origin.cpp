vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // make sure to use doubles
    priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, greater<pair<double, vector<int>>>> pq;
    for (auto p : points) {
        pq.push(pair<double, vector<int>>(sqrt((p[0] * p[0]) + (p[1] * p[1])), p));
    }

    vector<vector<int>> res;
    while (k > 0) {
        res.push_back(pq.top().second);
        pq.pop();
        k--;
    }

    return res;
}