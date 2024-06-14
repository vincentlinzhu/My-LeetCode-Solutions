int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int ts = 0;
    int s = 0;
    int start = 0;

    for (int i = 0; i < gas.size(); i++) {
        ts += gas[i] - cost[i];
        s += gas[i] - cost[i];
        if (s < 0) {
            s = 0;
            start = i + 1;
        } 
    }

    if (ts < 0) {
        return -1;
    }

    return start;
}