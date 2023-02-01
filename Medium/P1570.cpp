class SparseVector {
private:
    map<int, int> indexValueMap;

public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                indexValueMap.insert(pair<int, int>(i, nums[i]));
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for (auto it = vec.indexValueMap.begin(); it != vec.indexValueMap.end(); it++) {
            if (indexValueMap.find(it->first) != indexValueMap.end()) {
                res += (it->second * indexValueMap.find(it->first)->second);
            }
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
