#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int calculateAverage(vector<vector<int>>& submatrix) {
    int total = 0;
    int count = 0;
    for (auto & row : submatrix) {
        for (int value : row) {
            total += value;
            count++;
        }
    }
    
    return total/count;
}

vector<int> solution(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    
    int min_diff = INT_MAX;
    vector<int> result = {0, 0};
    
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            vector<vector<int>> submatrix1 (matrix.begin(), matrix.begin() + i);
            for (auto& row : submatrix1) {
                row.resize(j);
            }
            
            vector<vector<int>> submatrix2 (matrix.begin(), matrix.begin() + i);
            for (auto& row : submatrix2) {
                row.erase(row.begin(), row.begin() + j);
            }
            
            vector<vector<int>> submatrix3 (matrix.begin(), matrix.begin() + i);
            for (auto& row : submatrix3) {
                row.erase(row.begin(), row.begin() + j);
            }
            
            vector<vector<int>> submatrix4 (matrix.begin(), matrix.begin() + i);
            for (auto& row : submatrix4) {
                row.erase(row.begin(), row.begin() + j);
            }
            
            vector<int> averages = {
                calculateAverage(submatrix1),
                calculateAverage(submatrix2),
                calculateAverage(submatrix3),
                calculateAverage(submatrix4)
            };
            
            
            int max_avg = averages[0];
            int min_avg = averages[0];
            for (int k = 0; k < averages.size(); k++) {
                max_avg = max(max_avg, averages[k]);
                min_avg = min(min_avg, averages[k]);
            }
            int diff = max_avg - min_avg;
            
            if (diff < min_diff || (diff == min_diff && (i < result[0] || (i == result[0] && j < result[1])))) {
                min_diff = diff;
                result  = {i - 1, j - 1};
            } 
        }
    }
    
    return result;
}

int main()
{
    vector<vector<int>> m = {{-1, 70, 31, 99, 10 ,71},{61, 98, 98, 57, 51, 98},{53, 69, 31, 35, 56, 26},{83,54,17,100, 91, 4},{30,78, 97,
-1, 48,38},{78,28,51,27,12,11},{10,40, 7, 75,89,8},{97,52, 71, 67, 80,2}};

    for (auto x : solution(m)) {
        cout << x << endl;
    }
    //expected {2, 2}

    return 0;
}