// int fail() {
//     int l = 0;
//     int r = l;
//     int res = 0;
//     stack<pair<int, int>> s;
//     int len = 0;
//     int difference = 0;
//     int temp = 0;
//     int filled = 0;

//     if (height[r] < height[l]) { // you dip down: when this happens start keeping track
//         s.push(height[l]);
//         while (!s.empty()) {
//             while (r < height.size() && height[r] <= s.top().first) {
//                 s.push(pair<int, int>(height[r], 0));
//                 r++;
//                 if (height[r] == s.top().first) {
//                     s.top().second++;
//                 }
//             }
//             //height[r] > s.top().first
//             int potential = s.top().first;
//             len = s.top().second;
//             s.pop();
//             // right is shorter than new top
//             if (height[r] < s.top().first) {
//                 res += len * (height[r] - potential - filled);
//                 filled = height[r];
//             } else if (height[r] == s.top().first) { //right is same as new top
//                 res += len * s.top().first - potential;
//                 filled = height[r];
//                 s.pop();
//             } else { //right is taller than new top
//                 while (s.size() > 1 && height[r] > s.top().first) {
//                     difference = s.top().second * s.top().first;
//                     len += s.top().second;
//                     s.pop();
//                 }
//                 res += (min(s.top().first, height[r]) * len) - difference;
//                 filled = min(s.top().first, height[r]);
//             }
//             s.pop();
//         }
//     }

//     if (r >= l) {
//         l = r;
//     }

//     return res;
// }

// Linear Time & Constant Memory (2 pointer)
int trap(vector<int>& height) {
    int res = 0;
    int l = 0;
    int r = height.size() - 1;
    int maxL = height[l]; //current max height of the left
    int maxR = height[r]; //current max height of the right
    while (r > l) {
        if (maxL < maxR) { //Which ever is smaller is our bottleneck
            l++;
            if (maxL > height[l]) {
                res += maxL - height[l];
            } else {
                maxL = height[l];
            }
        } else {
            r--;
            if (maxR > height[r]) {
                res += maxR - height[r];
            } else {
                maxR = height[r];
            }
        }
    }

    return res;
}

// Linear Memory and Time
int trap(vector<int>& height) {
    int res = 0;
    vector<int> maxLeft;
    vector<int> maxRight (height.size(), 0);
    maxLeft.push_back(0);
    maxRight[height.size() - 1] = 0;

    for (int i = 1; i < height.size(); i++) {
        maxLeft.push_back(max(height[i - 1], maxLeft[i - 1]));
    }
    for (int i = height.size() - 2; i >= 0; i--) {
        maxRight[i] = (max(height[i + 1], maxRight[i + 1]));
    }
    for (int i = 0; i < height.size(); i++) {
        if (min(maxLeft[i], maxRight[i]) - height[i] > 0) {
            res += min(maxLeft[i], maxRight[i]) - height[i];
        }
    }

    return res;
}