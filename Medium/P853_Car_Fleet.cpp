int carFleet(int target, vector<int>& position, vector<int>& speed) {
    double time_arrival;
    vector<pair<int, double>> v;
    for (int i = 0; i < position.size(); i++) {
        time_arrival = (target - position[i])/(static_cast<double>(speed[i]));
        v.push_back(pair<int, double>(position[i], time_arrival));
    }
    sort(v.begin(), v.end());

    int res = position.size();
    stack<double> s;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (!s.empty() && v[i].second <= s.top()) {
            continue;
        } else {
            s.push(v[i].second);
        }
    }

    return s.size();
}