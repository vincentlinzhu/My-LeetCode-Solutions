int getMaximum(vector<int> arr) {
    vector<int> a(arr.size(), 0);
    vector<int> b(arr.size(), 0);
    a[0] = arr[0];
    b[0] = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        a[i] = a[i - 1] + arr[i];
    }
    
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= b[i - 1]) {
            b[i] = b[i - 1];
        } else {
            int temp = ceil(static_cast<double>(a[i])/static_cast<double>(i + 1));
            b[i] = max(b[i - 1], temp);
        }
    }
    
    return b[arr.size() - 1];
}