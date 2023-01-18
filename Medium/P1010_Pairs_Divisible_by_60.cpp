int numPairsDivisibleBy60(vector<int>& time) {
    int l = 0;
    int r = l + 1;
    int count = 0;

    map<int, int> m;
    for (int i = 0; i < time.size(); i++) {
        int compliment = 60 - (time[i] % 60);
        map<int, int>::iterator it = m.find(compliment);
        if (it != m.end()) {
            count += it->second;
        }
        
        if (time[i] % 60 == 0) {
            it = m.find(60);
            if (it != m.end()) {
                it->second++;
            } else {
                m.insert(pair<int, int>(60, 1));
            }
        }

        it = m.find(time[i] % 60);
        if (it != m.end()) {
            it->second++;
        } else {
            m.insert(pair<int, int>(time[i] % 60, 1));
        }
    }

    return count;
}