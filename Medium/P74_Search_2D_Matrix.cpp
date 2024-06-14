bool search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int m;
    while (r >= l) {
        m = (r - l)/2 + l;
        if (nums[m] == target) {
            return true;
        } else if (target < nums[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row_len = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;
    int middle;

    while (top <= bottom) {
        middle = (bottom - top)/2 + top;
        if (matrix[middle][0] <= target && matrix[middle][row_len] >= target) {
            return search(matrix[middle], target);
        } else if (target < matrix[middle][0]) {
            bottom = middle - 1;
        } else if (target > matrix[middle][row_len]) {
            top = middle + 1;
        }
    }
    return false;
}