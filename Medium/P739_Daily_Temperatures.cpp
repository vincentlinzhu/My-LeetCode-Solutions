vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    stack<pair<int, int>> s;
    int temp, index;
    for (int i = 0; i < temperatures.size(); i++) {
        while (!s.empty() && temperatures[i] > s.top().first) {
            temp = s.top().first;
            index = s.top().second;
            s.pop();
            res[index] = i - index;
        }
        s.push(pair<int, int>(temperatures[i], i));
    }
    return res;
}