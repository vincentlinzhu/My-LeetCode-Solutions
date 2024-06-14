vector<int> countBits(int n) {
    vector<int> res;
    res.push_back(0);
    int x = 1;
    int offset = 1;
    while (x <= n) {
        if (x/2 == offset) {
            offset = x;
            res.push_back(1);
        }
        else {
            res.push_back(1 + res[x - offset]);
        }
        x++;
    }
    return res;
}