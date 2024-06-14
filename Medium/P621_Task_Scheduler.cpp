// struct myComp {
//     constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b) const noexcept {
//         return a.second < b.second;
//     }
// };

int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> m;
    // priority_queue<pair<char, int>, vector<char, int>, myComp> pq;
    priority_queue<int> pq;
    queue<pair<int, int>> q;
    int time = 0;

    for (int i = 0; i < tasks.size(); i++) {
        if (m.count(tasks[i])) {
            m[tasks[i]]++;
        } else {
            m[tasks[i]] = 1;
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        pq.push(it->second);
    }

    int freq = 0;
    while (pq.size() > 0 || q.size() > 0) {
        time += 1;
        if (pq.size() > 0) {
            freq = pq.top() - 1; 
            pq.pop();
            if (freq != 0) {
                q.push(pair<int, int>(freq, time + n));
            }
        }
        if (q.size() > 0 && q.front().second == time) {
            pq.push(q.front().first);
            q.pop();
        }
    }

    return time;
}