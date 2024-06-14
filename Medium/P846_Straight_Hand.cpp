bool isNStraightHand(vector<int>& hand, int groupSize) {
    // sort(hand.begin(), hand.end());
    map<int, int> m;
    for (int i = 0; i < hand.size(); i++) {
        if (m.count(hand[i])) {
            m[hand[i]]++;
        } else {
            m[hand[i]] = 1;
        }
    }

    for (auto x : m) {
        if (m[x.first] > 0) {
            for (int i = groupSize - 1; i >= 0; i--) {
                if ((m[x.first + i] < m[x.first])) {
                    return false;
                }
                m[x.first + i] -= m[x.first];
            }
        }
    }
    return true;
}