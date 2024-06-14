void conquer(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int i = m + n - 1;
    while (p2 >= 0) {
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[i] = nums1[p1];
            p1--;
            i--;
        } else {
            nums1[i] = nums2[p2];
            p2--;
            i--;
        }
    }
}
void divide(vector<int>& nums) {
    // divide and conquer merge sort:
    // divide:
    if (nums.size() == 1) {
        return;
    }

    int m = nums.size()/2;
    
    vector<int> l (nums.begin(), nums.begin() + m);
    divide(l);
    int x = l.size();
    while (l.size() < nums.size()) {
        l.push_back(0);
    }

    vector<int> r (nums.begin() + m, nums.end());
    divide(r);
    
    //conquer:
    conquer(l, x, r, r.size());
    nums = l;
    return;

}
vector<int> sortArray(vector<int>& nums) {
    divide(nums);
    return nums;
}